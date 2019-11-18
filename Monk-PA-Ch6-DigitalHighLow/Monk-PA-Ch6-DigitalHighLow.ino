const int PIN_OUT_DIGITAL = 4;
const int PIN_OUT_ANALOG  = A4;

// Change this line to prove that you can use
// "digitalWrite" with the Analog Outs, too...
const int PIN_OUT = PIN_OUT_ANALOG;

void setup() {
  pinMode(PIN_OUT, OUTPUT);
  digitalWrite(PIN_OUT, LOW);
  Serial.begin(9600);
  Serial.println("Write 1 or 0 to turn on and off");
}

void loop() {
  if (Serial.available() > 0) {
    char val = Serial.read();
    if (val == '1') {
      digitalWrite(PIN_OUT, HIGH);
    } else if (val == '0') {
      digitalWrite(PIN_OUT, LOW);
    }
  }
}
