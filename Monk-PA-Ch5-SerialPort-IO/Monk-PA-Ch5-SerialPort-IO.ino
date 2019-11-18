
bool prompted;

void setup() {
  Serial.begin(9600);
  prompted = false;
}

void loop() {
  if (! prompted) {
    Serial.print("Please enter your query: ");
    prompted = true;
  } else if (Serial.available() > 0) {
    Serial.print("\nAnswer: " + Serial.readString());
    prompted = false;
  } 
}
