#include <ArduinoJson.h> // Работа с JSON объектом
#include <OneWire.h> // Интерфейс 1-Wire
#include <DallasTemperature.h> // Для работы DS18B20/DS18S20
#include "DHT.h"               // Для работы DHT11-22
//--Для ESP-8266--\\
//#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266httpUpdate.h>
#include <ESP8266HTTPClient.h>
#include <FS.h>
#include <Servo.h>
Servo myServo;
ESP8266HTTPUpdate upd;
ESP8266WebServer server(80);
HTTPClient httpPOST;
#define DEFAULT_UPDATE_URL "http://rubanao.ru/Smart_Metter_for_ESP-12F.bin"
#define BUILD "0.5"
const int att_mosipin = 13;
const int att_misopin = 12;
const int att_sckpin = 14;
const int att_cspin = 4;
const int att_rstpin = 5;
volatile long Lval;
volatile float Fval;
unsigned char AdcGainRegister[3] = {0x46, 0x55, 0x00};
unsigned char VoltageAdjustRegisterA[3] = {0x65, 0XEB, 0X34};
unsigned char VoltageAdjustRegisterB[3] = {0x66, 0XB5, 0X3A};
unsigned char VoltageAdjustRegisterC[3] = {0x64, 0X9A, 0X4E};
unsigned char CurrentAdjustRegisterA[3] = {0x0c, 0X43, 0X10};
unsigned char CurrentAdjustRegisterB[3] = {0x0C, 0X60, 0X4A};
unsigned char CurrentAdjustRegisterC[3] = {0x0B, 0xFC, 0X81};
unsigned char PowerAdjustRegisterA[3] = {0x1C, 0X5D, 0X9F};
unsigned char PowerAdjustRegisterB[3] = {0x1D, 0X29, 0X21};
unsigned char PowerAdjustRegisterC[3] = {0x1B, 0X55, 0X88};
long times = 0;
float BUFFER_DS[128];
File settings_File;
File fsUploadFile;
String settings_String = "";
IPAddress IP;
DynamicJsonBuffer jsonBuffer;



void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("==================================");
  Serial.println("Start programm");
  Serial.println("==================================");
  Serial.print((float)millis() * 0.001);
  Serial.print("sec. SPIFFS: check - ");
  if (SPIFFS.begin()) Serial.println("OK");
  else error(1);
  Serial.print((float)millis() * 0.001);
  Serial.print("sec. SPIFFS: check the settings file - ");
  if (SPIFFS_check()) Serial.println("OK");
  else {
    error(1);
    return;
  }
  Serial.print((float)millis() * 0.001);
  Serial.print("sec. SPIFFS: read the settings file - ");
  SPIFFS_file();
  JsonObject& root = jsonBuffer.parseObject(settings_String);
  if (root.success()) Serial.println("OK");
  else error(2);
  Serial.println(settings_String);
  Serial.print((float)millis() * 0.001);
  Serial.print("sec. WiFi mode: ");
  const char* A_SSID = root["WIFI_ssid"];
  const char* A_PASS = root["WIFI_pass"];
  const char* A_host = root["SERVER_hostname"];
  if (root["WIFI_mode"] == 1) {
    Serial.println("Client");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    Serial.print((float)millis() * 0.001);
    Serial.print("sec. WiFi: conecting - ");
    WiFi.begin(A_SSID, A_PASS);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.println("ERROR!");
      delay(5000);
      ESP.restart();
      error(3); 
    }
    IP = WiFi.localIP();
    Serial.print("OK!\nCLIENT MODE. IP: "); Serial.println(IP);
  }
  else {
    Serial.println("AP");
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(A_SSID, A_PASS);
    IP = WiFi.softAPIP();
    Serial.print("OK!\nAP MODE. IP: "); Serial.println(IP);
  }
  Serial.print((float)millis() * 0.001);
  Serial.print(" Start server - ");
  server.begin();
  server.on("/", handleRoot);
  server.on("/reboot", handleReboot);
  server.on("/reset", handleReset);
  //server.on("/update", handleUpdate);
  server.on("/build", handleBuild);
  server.on("/commands", HTTP_POST, handlePOST);
  Serial.println("OK!");
}

void loop() {
  JsonObject& root = jsonBuffer.parseObject(settings_String);
  server.handleClient();
  if (WiFi.status() == WL_CONNECTED) {
    if (millis() - times >= 10000) {
      times = millis();
      //send_data_POST(preparation_data());
    }
  }
}





