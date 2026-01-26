#include <Wire.h>
#include <Adafruit_VL53L0X.h>

#define TCA_ADDR 0x70
const uint8_t N = 4;
const uint8_t chan[N] = {0, 1, 2, 3};

Adafruit_VL53L0X lox[N];

void tcaSelect(uint8_t ch) {
  if (ch > 7) return;
  Wire.beginTransmission(TCA_ADDR);
  Wire.write(1 << ch);
  Wire.endTransmission();
}

bool initVL53(uint8_t i) {
  tcaSelect(chan[i]);
  delay(10);
  // false = sin debug
  return lox[i].begin();
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  Wire.begin();
  Wire.setClock(100000); // si tienes cables/pullups, 100kHz es más estable

  Serial.println("Init 4x VL53L0X via TCA9548A");

  for (uint8_t i = 0; i < N; i++) {
    if (initVL53(i)) {
      Serial.print("Sensor "); Serial.print(i);
      Serial.print(" OK en canal "); Serial.println(chan[i]);
    } else {
      Serial.print("Sensor "); Serial.print(i);
      Serial.print(" FAIL en canal "); Serial.println(chan[i]);
    }
  }
}

void loop() {
  for (uint8_t i = 0; i < N; i++) {
    tcaSelect(chan[i]);

    VL53L0X_RangingMeasurementData_t measure;
    lox[i].rangingTest(&measure, false);

    Serial.print("CH"); Serial.print(chan[i]); Serial.print(": ");

    if (measure.RangeStatus != 4) { // 4 = out of range
      Serial.print(measure.RangeMilliMeter);
      Serial.print(" mm");
    } else {
      Serial.print("Out of range");
    }

    Serial.print(" | ");
  }
  Serial.println();
  delay(50);
}
