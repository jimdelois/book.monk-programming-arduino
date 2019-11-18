const int PIN_IN_DIGITAL = 5;
const int PIN_IN_ANALOG = A5;

const int PIN_IN = PIN_IN_ANALOG;

void setup() {
  pinMode(PIN_IN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(PIN_IN);
  //
  float voltage = reading / (1023.0/5.0);
  Serial.print("Reading: ");
  Serial.print(reading);
  Serial.print("\t\tVoltage: ");
  Serial.println(voltage);
  delay(1000);
}
