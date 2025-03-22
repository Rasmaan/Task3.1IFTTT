// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)

void onIntensityLightChange();

float intensity_light;

void initProperties(){

  ArduinoCloud.addProperty(intensity_light, READWRITE, ON_CHANGE, onIntensityLightChange);



}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
