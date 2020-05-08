bool SPIFFS_check() {
  if (!(settings_File = SPIFFS.open("/settings.txt", "r"))) return false;
  else return true;
}
bool SPIFFS_file() {
  if (settings_File) {
    while (settings_File.available()) {
      settings_String += (char)settings_File.read();
    }
    settings_File.close();
    return true;
  }
  else return false;
}
void loadfileSet() {
  const char* A_SSID = "Smart_Metter";
  const char* A_PASS = "";
  Serial.print((float)millis() * 0.001);
  Serial.print("sec. WiFi mode: ");
  Serial.println("AP");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(A_SSID, A_PASS);
  IP = WiFi.softAPIP();
  Serial.print("OK!\nAP MODE. IP: "); Serial.println(IP);
  Serial.print((float)millis() * 0.001);
  Serial.print(" Start server - ");
  server.begin();
  server.on("/", handleLoad);
  server.on("/upload", HTTP_POST, []() {
    server.send(200, "text/plain", "");
  }, handleFileUpload);
  Serial.println("OK!");
}
String getContentType(String filename) {
  if (server.hasArg("download")) return "application/octet-stream";
  else if (filename.endsWith(".txt")) return "text/plain";
  else if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".htm")) return "text/htm";
  else if (filename.endsWith(".jpg")) return "image/jpeg";
  else if (filename.endsWith(".png")) return "image/png";
  else if (filename.endsWith(".svg")) return "image/svg+xml";
  return "text/plain";
}
void handleFileUpload() {
  HTTPUpload& upload = server.upload();
  if (upload.status == UPLOAD_FILE_START) {
    String filename = upload.filename;
    if (!filename.startsWith("/")) filename = "/" + filename;
    fsUploadFile = SPIFFS.open(filename, "w");
    filename = String();
  } else if (upload.status == UPLOAD_FILE_WRITE) {
    if (fsUploadFile)
      fsUploadFile.write(upload.buf, upload.currentSize);
  } else if (upload.status == UPLOAD_FILE_END) {
    if (fsUploadFile)
      fsUploadFile.close();
  }
}
void handleLoad() {
  server.send(200, "text/html", "<h1>Upload settings page!</h1><form action='/upload' method='post' enctype='multipart/form-data'><input type='file' name='name'><input class='button' type='submit' value='Upload'></form>");
}
