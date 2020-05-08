void error(byte code) {
  switch (code) {
    case 1: Serial.println("ERROR! \nReboot after 5 seconds..."); loadfileSet(); return; break;
    case 2: Serial.println("ERROR! Bad file. \nReboot after 5 seconds..."); break;
    case 3: Serial.println("ERROR! Connection Failed. \nReboot after 5 seconds..."); break;
    case 40: server.send(400, "text/html", "Bad Request"); break;
    default: Serial.println("WO WO WO O_o! \nReboot after 5 seconds...");
  }
  delay(5000);
  ESP.restart();
}


