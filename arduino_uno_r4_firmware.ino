// Basic demo for readings from Adafruit SCD30
#include <Adafruit_SCD30.h>
#include <Wire.h>

Adafruit_SCD30  scd30;


void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  // Try to initialize!
  if (!scd30.begin(0x61, &Wire1, 0)) {
    Serial.println("Failed to find SCD30 sensor");
    while (1) { delay(10); }
  }
  Serial.println("Found SCD30 sensor");


  if (!scd30.setMeasurementInterval(60)){
    Serial.println("Failed to set measurement interval");
    while(1){ delay(10);}
  }
  Serial.print("Measurement interval set to "); 
  Serial.print(scd30.getMeasurementInterval()); 
  Serial.println(" seconds");
}

void loop() {
  if (scd30.dataReady()){
    if (!scd30.read()){ Serial.println("Error reading sensor data"); return; }

    Serial.print(scd30.temperature);
    Serial.print(",");
    Serial.print(scd30.relative_humidity);
    Serial.print(",");
    Serial.println(scd30.CO2, 3);
  }

  delay(100);
}