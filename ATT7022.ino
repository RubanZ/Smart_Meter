volatile float ATT(String command) {
  pinMode(att_mosipin, OUTPUT);
  pinMode(att_misopin, INPUT);
  pinMode(att_sckpin, OUTPUT);
  pinMode(att_cspin, OUTPUT);
  pinMode(att_rstpin, OUTPUT);

  digitalWrite(att_cspin, HIGH);
  digitalWrite(att_sckpin, LOW);
  digitalWrite(att_mosipin, LOW);
  digitalWrite(att_rstpin, HIGH);
  if (command == "0x01") {
    Lval = ReadSampleRegister(0x01);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x02") {
    Lval = ReadSampleRegister(0x02);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x03") {
    Lval = ReadSampleRegister(0x03);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x04") {
    Lval = ReadSampleRegister(0x04);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 17)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x05") {
    Lval = ReadSampleRegister(0x05);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x06") {
    Lval = ReadSampleRegister(0x06);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x07") {
    Lval = ReadSampleRegister(0x07);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x08") {
    Lval = ReadSampleRegister(0x08);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 17)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x09") {
    Lval = ReadSampleRegister(0x09);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x0A") {
    Lval = ReadSampleRegister(0x0A);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x0B") {
    Lval = ReadSampleRegister(0x0B);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x0C") {
    Lval = ReadSampleRegister(0x0C);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 17)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x0D") {
    Lval = ReadSampleRegister(0x0D);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x0E") {
    Lval = ReadSampleRegister(0x0E);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x0F") {
    Lval = ReadSampleRegister(0x0F);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x10") {
    Lval = ReadSampleRegister(0x10);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x11") {
    Lval = ReadSampleRegister(0x11);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x12") {
    Lval = ReadSampleRegister(0x12);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x13") {
    Lval = ReadSampleRegister(0x13);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x29") {
    Lval = ReadSampleRegister(0x29);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x2B") {
    Lval = ReadSampleRegister(0x2B);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x14") {
    Lval = ReadSampleRegister(0x14);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    Fval = (Lval) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x15") {
    Lval = ReadSampleRegister(0x15);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    Fval = (Lval) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x16") {
    Lval = ReadSampleRegister(0x16);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    Fval = (Lval) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x17") {
    Lval = ReadSampleRegister(0x17);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    Fval = (Lval) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x18") {
    Lval = ReadSampleRegister(0x18);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    else {
      Lval = 0;
    }
    Fval = (Lval / pow(2, 23)) * 2 * 180 / PI;
    return Fval;
  }
  else if (command == "0x19") {
    Lval = ReadSampleRegister(0x19);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    else {
      Lval = 0;
    }
    Fval = (Lval / pow(2, 23)) * 2 * 180 / PI;
    return Fval;
  }
  else if (command == "0x1A") {
    Lval = ReadSampleRegister(0x1A);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    else {
      Lval = 0;
    }
    Fval = (Lval / pow(2, 23)) * 2 * 180 / PI;
    return Fval;
  }
  else if (command == "0x1B") {
    Lval = ReadSampleRegister(0x1B);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    else {
      Lval = 0;
    }
    Fval = (Lval / pow(2, 23)) * 2 * 180 / PI;
    return Fval;
  }
  else if (command == "0x1C") {
    Lval = ReadSampleRegister(0x1C);
    Fval = Lval * pow(2, 10) / pow(2, 23);
    return Fval;
  }
  else if (command == "0x1D") {
    Lval = ReadSampleRegister(0x1D);
    return Lval;
  }
  else if (command == "0x1E") {
    Lval = ReadSampleRegister(0x1E);
    return Lval;
  }
  else if (command == "0x1F") {
    Lval = ReadSampleRegister(0x1F);
    return Lval;
  }
  else if (command == "0x20") {
    Lval = ReadSampleRegister(0x20);
    return Lval;
  }
  else if (command == "0x21") {
    Lval = ReadSampleRegister(0x21);
    return Lval;
  }
  else if (command == "0x22") {
    Lval = ReadSampleRegister(0x22);
    return Lval;
  }
  else if (command == "0x23") {
    Lval = ReadSampleRegister(0x23);
    return Lval;
  }
  else if (command == "0x24") {
    Lval = ReadSampleRegister(0x24);
    return Lval;
  }
  else if (command == "0x25") {
    Lval = ReadSampleRegister(0x25);
    return Lval;
  }
  else if (command == "0x31") {
    Lval = ReadSampleRegister(0x31);
    return Lval;
  }
  else if (command == "0x32") {
    Lval = ReadSampleRegister(0x32);
    return Lval;
  }
  else if (command == "0x33") {
    Lval = ReadSampleRegister(0x33);
    return Lval;
  }
  else if (command == "0x34") {
    Lval = ReadSampleRegister(0x34);
    return Lval;
  }
  else if (command == "0x35") {
    Lval = ReadSampleRegister(0x35);
    return Lval;
  }
  else if (command == "0x36") {
    Lval = ReadSampleRegister(0x36);
    return Lval;
  }
  else if (command == "0x37") {
    Lval = ReadSampleRegister(0x37);
    return Lval;
  }
  else if (command == "0x38") {
    Lval = ReadSampleRegister(0x38);
    return Lval;
  }
  else if (command == "0x40") {
    Lval = ReadSampleRegister(0x40);
    return Lval;
  }
  else if (command == "0x41") {
    Lval = ReadSampleRegister(0x41);
    return Lval;
  }
  else if (command == "0x42") {
    Lval = ReadSampleRegister(0x42);
    return Lval;
  }
  else if (command == "0x43") {
    Lval = ReadSampleRegister(0x43);
    return Lval;
  }
  else if (command == "0x44") {
    Lval = ReadSampleRegister(0x44);
    return Lval;
  }
  else if (command == "0x45") {
    Lval = ReadSampleRegister(0x45);
    return Lval;
  }
  else if (command == "0x46") {
    Lval = ReadSampleRegister(0x46);
    return Lval;
  }
  else if (command == "0x47") {
    Lval = ReadSampleRegister(0x47);
    return Lval;
  }
  else if (command == "0x48") {
    Lval = ReadSampleRegister(0x48);
    return Lval;
  }
  else if (command == "0x49") {
    Lval = ReadSampleRegister(0x49);
    return Lval;
  }
  else if (command == "0x4A") {
    Lval = ReadSampleRegister(0x4A);
    return Lval;
  }
  else if (command == "0x4B") {
    Lval = ReadSampleRegister(0x4B);
    return Lval;
  }
  else if (command == "0x4C") {
    Lval = ReadSampleRegister(0x4C);
    return Lval;
  }
  else if (command == "0x4D") {
    Lval = ReadSampleRegister(0x4D);
    return Lval;
  }
  else if (command == "0x4E") {
    Lval = ReadSampleRegister(0x4E);
    return Lval;
  }
  else if (command == "0x4F") {
    Lval = ReadSampleRegister(0x4F);
    return Lval;
  }
  else if (command == "0x60") {
    Lval = ReadSampleRegister(0x60);
    return Lval;
  }
  else if (command == "0x61") {
    Lval = ReadSampleRegister(0x61);
    return Lval;
  }
  else if (command == "0x62") {
    Lval = ReadSampleRegister(0x62);
    return Lval;
  }
  else if (command == "0x63") {
    Lval = ReadSampleRegister(0x63);
    return Lval;
  }
  else if (command == "0x64") {
    Lval = ReadSampleRegister(0x64);
    return Lval;
  }
  else if (command == "0x65") {
    Lval = ReadSampleRegister(0x65);
    return Lval;
  }
  else if (command == "0x66") {
    Lval = ReadSampleRegister(0x66);
    return Lval;
  }
  else if (command == "0x67") {
    Lval = ReadSampleRegister(0x67);
    return Lval;
  }
  else if (command == "0x68") {
    Lval = ReadSampleRegister(0x68);
    return Lval;
  }
  else if (command == "0x69") {
    Lval = ReadSampleRegister(0x69);
    return Lval;
  }
  else if (command == "0x6A") {
    Lval = ReadSampleRegister(0x6A);
    return Lval;
  }
  else if (command == "0x6B") {
    Lval = ReadSampleRegister(0x6B);
    return Lval;
  }
  else if (command == "0x6C") {
    Lval = ReadSampleRegister(0x6C);
    return Lval;
  }
  else if (command == "0x6D") {
    Lval = ReadSampleRegister(0x6D);
    return Lval;
  }
  else if (command == "0x6E") {
    Lval = ReadSampleRegister(0x6E);
    return Lval;
  }
  else if (command == "0x6F") {
    Lval = ReadSampleRegister(0x6F);
    return Lval;
  }
  else if (command == "0x28") {
    Lval = ReadSampleRegister(0x28);
    return Lval;
  }
  else if (command == "0x2D") {
    Lval = ReadSampleRegister(0x2D);
    return Lval;
  }
  else if (command == "0x2E") {
    Lval = ReadSampleRegister(0x2E);
    return Lval;
  }
  else if (command == "0x2C") {
    return 0;
  }
  else if (command == "0x30") {
    return 0;
  }
  else if (command == "0x3D") {
    return 0;
  }
  else if (command == "0x3E") {
    return 0;
  }
  else if (command == "0x5C") {
    Lval = ReadSampleRegister(0x5C);
    Fval = Lval/ pow(2, 23);
    return Fval;
  }
  else if (command == "0x5D") {
    return 0;
  }
  else if (command == "0x5E") {
    return 0;
  }
  else if (command == "0x5F") {
    return 0;
  }
  else return 0;
}
long SPIRead(unsigned char Cmd) {
  int n;
  long data;

  data = 0;
  digitalWrite(att_cspin, LOW);

  for (n = 7; n >= 0; n--)
  {
    digitalWrite(att_sckpin, HIGH);
    digitalWrite(att_mosipin, (Cmd & (1 << n)) >> n);
    digitalWrite(att_sckpin, LOW);
  }
  delayMicroseconds(5);
  for (n = 23; n >= 0; n--)
  {
    digitalWrite(att_sckpin, HIGH);
    data = data | (digitalRead(att_misopin) << n);
    digitalWrite(att_sckpin, LOW);
  }
  digitalWrite(att_cspin, HIGH);
  if (data == 1024 || data == 2048) {
    data = SPIRead(Cmd);
  }
  return data;
}
void SPIWrite(unsigned char Cmd, long val) {
  int n;

  digitalWrite(att_cspin, HIGH);
  digitalWrite(att_sckpin, LOW);
  digitalWrite(att_cspin, LOW);

  for (int n = 7; n >= 0; n--)
  {
    digitalWrite(att_sckpin, HIGH);
    digitalWrite(att_mosipin, (Cmd & (1 << n)) >> n);
    digitalWrite(att_sckpin, LOW);
  }
  for (int n = 23; n >= 0; n--)
  {
    digitalWrite(att_sckpin, HIGH);
    //Lval = Lval | (digitalRead(att_misopin) << n);
    asm("nop");
    asm("nop");
    asm("nop");
    digitalWrite(att_mosipin, (val & (1 << n)) >> n);
    digitalWrite(att_sckpin, LOW);
  }
  digitalWrite(att_cspin, HIGH);
}
long ReadSampleRegister(unsigned char cmd) {
  long datatemp;

  datatemp = 0;
  SPIWrite(0xC6, 0x00000);
  delayMicroseconds(50);

  datatemp = SPIRead(cmd);

  return datatemp;
}
void ResetATT7022(void) {
  digitalWrite(att_rstpin, LOW);
  delayMicroseconds(20);
  digitalWrite(att_rstpin, HIGH);
  delayMicroseconds(200);
}
void WriteAdjustRegister(unsigned char addr, long val) {
  SPIWrite(0xC9, 0x000000);
  delayMicroseconds(50);
  SPIWrite(addr, val);
  delayMicroseconds(50);
  SPIWrite(0xC9, 0x000001);
  delayMicroseconds(200);
}
void ReadAdjustRegister(unsigned char addr, unsigned char *tmpbuf) {
  long data;

  data = 0;
  SPIWrite(0xC6, 0x00005A);
  delayMicroseconds(10);
  data = SPIRead(addr);
  memcpy(tmpbuf, &data, 3);
  delayMicroseconds(100);
}
void AdjustVoltageFrun(float StandValue, unsigned char PhaseType) {
  unsigned char    AdjustBuff[3];
  float RealVol ;
  float Ugain;
  long  Uadjust;

  RealVol = ReadSampleRegister(0x0D + PhaseType) / 8192.00;
  Ugain = (StandValue / RealVol) - 1;
  if (Ugain > 0)
    Ugain = Ugain * 8388608;
  else
    Ugain = Ugain * 8388608 + 16777216;

  Uadjust = (long)Ugain;
  WriteAdjustRegister(0x1b + PhaseType, 0x000000);
  WriteAdjustRegister(0x1B + PhaseType, Uadjust);
  if (PhaseType == 0)
    ReadAdjustRegister(0x1B + PhaseType, VoltageAdjustRegisterA);
  else if (PhaseType == 1)
    ReadAdjustRegister(0x1B + PhaseType, VoltageAdjustRegisterB);
  else if (PhaseType == 2)
    ReadAdjustRegister(0x1B + PhaseType, VoltageAdjustRegisterC);
}
void AdjustPowerGain(float StandValue , unsigned char PhaseType) {
  unsigned char    tmpBuff[3] = {0x00, 0x00, 0x00};
  float RmsMesurePower ;
  float ERR , PgainX;
  long Pgain;
  unsigned char    AdjustBuff[3];
  RmsMesurePower = (float)(ReadSampleRegister(0X01 + PhaseType) / 256.0);
  ERR = (RmsMesurePower - StandValue) / StandValue;
  PgainX = (0 - ERR) / (1 + ERR);
  if (PgainX >= 0)
    Pgain = PgainX * 8388608;
  else
    Pgain = 16777216 + PgainX * 8388608;
  WriteAdjustRegister(0x06 + PhaseType, 0x000000);
  WriteAdjustRegister(0X06 + PhaseType, Pgain);
  WriteAdjustRegister(0X09 + PhaseType, Pgain);
  if (PhaseType == 0)
    ReadAdjustRegister(0x06 + PhaseType, PowerAdjustRegisterA);
  else if (PhaseType == 1)
    ReadAdjustRegister(0x06 + PhaseType, PowerAdjustRegisterB);
  else if (PhaseType == 2)
    ReadAdjustRegister(0x06 + PhaseType, PowerAdjustRegisterC);
}
void AdjustCurrentFrun(float StandValue, unsigned char PhaseType) {
  unsigned char    tmpBuff[3] = {0x00, 0x00, 0x00};
  unsigned char    AdjustBuff[3];
  float RealCur ;
  float Ugain;
  long  Uadjust;

  RealCur = (ReadSampleRegister(0x10 + PhaseType) & 0x7fffff) / 8192.00;
  Ugain = (StandValue / RealCur) - 1;
  if (Ugain >= 0)
    Ugain = Ugain * 8388608;
  else
    Ugain = Ugain * 8388608 + 16777216;

  Uadjust = (long)Ugain;
  WriteAdjustRegister(0x26 + PhaseType, 0x000000);
  WriteAdjustRegister(0x26 + PhaseType, Uadjust);
  if (PhaseType == 0)
    ReadAdjustRegister(0x26 + PhaseType, CurrentAdjustRegisterA);
  else if (PhaseType == 1)
    ReadAdjustRegister(0x26 + PhaseType, CurrentAdjustRegisterB);
  else if (PhaseType == 2)
    ReadAdjustRegister(0x26 + PhaseType, CurrentAdjustRegisterC);
}
void ClearAdjustRegister(void) {
  SPIWrite(0xC3, 0x000000);
  delayMicroseconds(200);
}
unsigned char ConfigAdjustRegister(void) {
  WriteAdjustRegister(0x1B + 0, (long)VoltageAdjustRegisterA);
  WriteAdjustRegister(0x1B + 1, (long)VoltageAdjustRegisterB);
  WriteAdjustRegister(0x1B + 2, (long)VoltageAdjustRegisterC);
  WriteAdjustRegister(0x26 + 0, (long)CurrentAdjustRegisterA);
  WriteAdjustRegister(0x26 + 1, (long)CurrentAdjustRegisterB);
  WriteAdjustRegister(0x26 + 2, (long)CurrentAdjustRegisterC);
  WriteAdjustRegister(0x06 + 0, (long)PowerAdjustRegisterA);
  WriteAdjustRegister(0x06 + 1, (long)PowerAdjustRegisterB);
  WriteAdjustRegister(0x06 + 2, (long)PowerAdjustRegisterC);
  WriteAdjustRegister(0x09 + 0, (long)PowerAdjustRegisterA);
  WriteAdjustRegister(0x09 + 1, (long)PowerAdjustRegisterB);
  WriteAdjustRegister(0x09 + 2, (long)PowerAdjustRegisterC);
  return 0;
}
