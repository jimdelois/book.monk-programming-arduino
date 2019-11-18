const int PIN_OUT = 3;

void setup() {
  pinMode(PIN_OUT, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter Voltage, 0-5");
}

void loop() {
  if (Serial.available() > 0) {
    float volts = Serial.parseFloat();
    // The values actually sent to the PWM is 0-255
    int pwmValue = volts * 255.0 / 5.0;
    analogWrite(PIN_OUT, pwmValue);
  }
}
