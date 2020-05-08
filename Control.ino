bool Led(int pin, int state) {
  if (state == 0) {
    digitalWrite(pin, state);
    pinMode(pin, INPUT);
    return true;
  } else if (state == 1) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, state);
    return true;
  } else return false;
}

