String FuncDHT(int pin) {
  DHT dhtOne;
  dhtOne.setup(pin);
  delay(dhtOne.getMinimumSamplingPeriod());
  return String(dhtOne.getHumidity());
}

String FuncDHT_temp(int pin) {
  DHT dhtOne;
  dhtOne.setup(pin);
  delay(dhtOne.getMinimumSamplingPeriod());
  return String(dhtOne.getTemperature());
}

int servo(int pin, int angel){
  myServo.attach(pin);

  myServo.write(angel);
  delay(100);
  myServo.detach();
  return angel;
}

float ds18sb20(int pin, int id) {
  OneWire oneWire1(pin);
  DallasTemperature sensors(&oneWire1);
  DeviceAddress addr;
  sensors.begin();
  if (!sensors.getAddress(addr, id)) {
    return -255;
  } else {
    oneWire1.search(addr);
    sensors.setResolution(addr, 9);
    sensors.requestTemperatures();
    float temp = sensors.getTempC(addr);
    return temp;
  }
}

float current() {
  pinMode(A0, INPUT);
  float c = 0.00;
  for (int i = 0; i < 5; i++) {
    c = analogRead(A0) * 5.0 / 1024.0;
    if (c != 0) {
      break;
    }
  }
  return c;
}
