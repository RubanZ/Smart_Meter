void handlePOST(){
  Serial.print("POST - ");
  Serial.println(server.arg(0));
  String mess = "";
  DynamicJsonBuffer BufferArray;
  JsonArray& POST = BufferArray.parseArray(server.arg(0));
  server.sendHeader("Connection",  "keep-alive");
  server.sendHeader("Keep-Alive",  "300", false);//Allow-Control-Allow-Origin: *
  server.sendHeader("Allow-Control-Allow-Origin", "*");
  server.setContentLength(200);
  //server.send(200, "text/html", "Test");
  for (int i = 0; i < POST.size(); i++){
    DynamicJsonBuffer BufferPOST;
    JsonObject& ARG = BufferPOST.parseObject(POST.get<String>(i));
    String t = ARG["t"];
    String v = ARG["v"];
    String p = ARG["p"];
    
    if (t == "at") server.sendContent(String(ATT(p)));
    else if (t == "ds") server.sendContent(String(FuncDHT_temp(p.toInt())));
    else if (t == "dh") server.sendContent(String(FuncDHT(p.toInt())));
    else if (t == "se") server.sendContent(String(servo(p.toInt(), v.toInt())));
    else if (t == "sw") server.sendContent(String(Led(p.toInt(), v.toInt())));
    else server.sendContent("error");
    server.sendContent(";");
  }
  //server.stop();
  //server.send(200, "text/html", mess);
  Serial.println("Send");
}

void handleCmd() {
  if (server.hasArg("count")) {
    String mess = "";
    //int count_command = server.arg("count").toInt();
    if (server.hasArg("DS18B20pin") && server.hasArg("DS18B20id")) {
      mess += "DS18B20";
      mess += server.arg("DS18B20id");
      mess += ": ";
      int pin = server.arg("DS18B20pin").toInt();
      int id = server.arg("DS18B20id").toInt();
      mess += String(ds18sb20(pin, id));
      mess += "\n\r";
    }
    if (server.hasArg("DHTpin")) {
      int pin = server.arg("DHTpin").toInt();
      mess += "DHT: ";
      mess += String(FuncDHT(pin));
      mess += "\n\r";
    }
    if (server.hasArg("Led")) {
      int pin = server.arg("Ledpin").toInt();
      int state = server.arg("Ledstate").toInt();
      mess += "Led: ";
      if (Led(pin, state)) {
        mess += "ok";
      } else {
        mess += "error";
      }
      mess += "\n\r";
    }
    if (server.hasArg("Current")) {
    mess += "Current: ";
    mess += String(current());
      mess += "\n\r";
    }
    for (int i = 0; server.hasArg("ATTCmd" + String(i+1)); i++) {
    String command = server.arg("ATTCmd");
      mess += "ATTCmd";
      mess += String(i+1);
      mess += ": ";
      mess += String(ATT(command));
      mess += "\n\r";
    }
    server.send(200, "text/html", mess);
  } else {
    error(40);
  }
}

void handleLed() {
  int pin = server.arg("pin").toInt();
  int state = server.arg("state").toInt();
  if (Led(pin, state)) {
    server.send(200, "text/html", "ok");
  }
  else {
    error(40);
  }
}

void handleCurrent() {
  String mess = String(current());
  server.send(200, "text/html", mess);
}

void handleDht() {
  int pin = server.arg("pin").toInt();
  String mess = String(FuncDHT(pin));
  server.send(200, "text/html", mess);
}

void handleCurrentD() {
  String command = server.arg("command");
  String mess = String(ATT(command));
  server.send(200, "text/html", mess);
}

void handleDS() {
  int pin = server.arg("pin").toInt();
  int id = server.arg("id").toInt();
  String mess = String(ds18sb20(pin, id));
  server.send(200, "text/html", mess);
}

void handleReboot() {
  server.send(200, "text/html", "Reboot");
  ESP.restart();
}
void handleUpdate() {
  update();
  server.send(200, "text/html", "Update");
}
void handleBuild() {
  server.send(200, "text/html", BUILD);
}
void handleRoot() {
  String mess = "OK. STARTED.";
  server.send(200, "text/html", mess);
}
void handleReset() {
  server.send(200, "text/html", "EEPROM RESET");
  ESP.restart();
}

String Hex_to_int_mac() {
  int mac;
  byte macHEX[6];
  String macString = "";
  WiFi.macAddress(macHEX);
  for (int i = 0; i < 6; i++) {
    mac += macHEX[i] / 10 * i;
    macString += macHEX[i];
  }
  return macString;
}

void update() {
  t_httpUpdate_return rez = ESPhttpUpdate.update(DEFAULT_UPDATE_URL, BUILD);
  return;
}
