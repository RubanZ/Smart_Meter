void send_data_POST(String obj){
  Serial.println(obj);
  httpPOST.begin("http://94.154.14.1/api/data");
  httpPOST.addHeader("Content-Type", "application/json");

  int httpCodePOST = httpPOST.POST(obj);
  String payloadPOST = httpPOST.getString(); 
  Serial.print(httpCodePOST);
  Serial.print(" - "); 
  Serial.println(payloadPOST);
  httpPOST.end();
}

String preparation_data(){
  //{ "token": 8362592375, "fulldata": [ {"alias": "name_alias", "data": [2147, 71246, 612746, 21846]}, {"alias": "name_alias", "data": [2147, 71246, 612746, 21846]} ] }
  String result = "{ \"token\": ";
  result += "\"2b6be3eb938bf63ae3326f094ffe43c\"";
  result += ", \"fulldata\": ";
  
  result += "[{\"alias\": \"temp\", \"data\": ";
  result += String((int)ds18sb20(12, 0));
  result += "}, ";

  result += "{\"alias\": \"wetness\", \"data\": ";
  result += FuncDHT(2);
  result += "}, ";

  result += "{\"alias\": \"power\", \"data\": \"";
  result += String(ATT("0x04"));
  result += "\"}, ";

  result += "{\"alias\": \"powera\", \"data\": \"";
  result += String(ATT("0x01"));
  result += "\"}, ";

  result += "{\"alias\": \"powerb\", \"data\": \"";
  result += String(ATT("0x02"));
  result += "\"}, ";

  result += "{\"alias\": \"powerc\", \"data\": \"";
  result += String(ATT("0x03"));
  result += "\"}, ";
  
  result += "{\"alias\": \"current\", \"data\": \"";
  result += String(ATT("0x13"));
  result += "\"}, ";
  result += "{\"alias\": \"voltage\", \"data\": \"";
  result += String(ATT("0x2B"));
  result += "\"} ";
  
  result += "]}";
  return result;
}

void GET() {
  
  String MQTT_mess = "";
  String mess = "http://194.87.99.81:70/mearsurements.php";


  
  /*mess += "?id_device=";
  mess += Hex_to_int_mac();
  
  mess += "&tem";
  mess += String((int)ds18sb20(root["DS_pin"], i));
  
  mess +=  "&wetness=";
  mess += FuncDHT((int)root["wetness_pin"]);
  
  mess += "&power=";
  mess += String(ATT("0x04"));

  mess += "&powera=";
  mess += String(ATT("0x01"));

  mess += "&powerb=";
  mess += String(ATT("0x02"));

  mess += "&powerc=";
  mess += String(ATT("0x03"));
  
  mess += "&current=";
  mess += String(ATT("0x13"));
  
  mess += "&voltage=";
  mess += String(ATT("0x2B"));

  HTTPClient http;
  http.begin(mess);
  Serial.println(mess);
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();*/
}
