#include "arduino_secrets.h"
#include <WiFiNINA.h>
#include <BH1750FVI.h>

#include "thingProperties.h"

BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

void setup() {  
  Serial.begin(9600);
  delay(1500);
  LightSensor.begin();

  initProperties();

  // connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update(); //keeps arduino connected to the iot cloud and syncs cloud variables
  
  float lux = LightSensor.GetLightIntensity();
  intensity_light = lux;
  if (lux > 300)
  {
    Serial.print("There is sunlight");
    Serial.print("Lux Value is ");
    Serial.println(intensity_light);
    delay(5000);
  }
  else
  {
    Serial.print("There is no sunlight");
    Serial.print("Lux value is ");
    Serial.println(intensity_light);
    delay(5000);
  }
}

// this function will handle changes in the intensity_light variable
void onIntensityLightChange() {
  
  if (intensity_light > 300) {
    Serial.println("Sunlight detected, triggering IFTTT notification...");
  } else {
    Serial.println("No sunlight detected, triggering IFTTT notification...");
  }
}
