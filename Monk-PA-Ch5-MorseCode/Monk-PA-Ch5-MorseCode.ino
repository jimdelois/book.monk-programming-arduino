// Could be char bootMessage[] = ...
//  But the point notation is more common
//  Just using this as a random example
const char *bootMessage = "Morse Code Blinker Started.";

const char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};
const char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-",
  ".....", "-....", "--...", "---..", "----."
};

const int DURATION_DOT =               90;
const int DURATION_DASH =              DURATION_DOT * 3;
const int DURATION_SEPARATOR_LETTERS = DURATION_DASH;
const int DURATION_SEPARATOR_DOTS =    DURATION_DOT;
const int DURATION_SPACE =             DURATION_DOT * 4;

const int PIN_LED = 2;
const int PIN_AUDIO = 3; // If connected, should be an ACTIVE buzzer.
                         // The addition of an audio module combines
                         // the Elegoo tutorial with this one. It was
                         // not a part of the original Monk-PA tutorial

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_AUDIO, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_AUDIO, LOW);

  Serial.begin(9600);
  Serial.println(bootMessage);
}

void loop() {
  char c;
  if (Serial.available() > 0) {
    c = Serial.read();
    if (c == ' ') { delay(DURATION_SPACE); return; }

    if(c >= 'a' && c <= 'z') {
      flashSequence(letters[c - 'a']);
    } else if(c >= 'A' && c <= 'Z') {
      flashSequence(letters[c - 'A']);
    } else if(c >= '0' && c <= '9') {
      flashSequence(numbers[c - '0']);
    }
  }
}

void flashSequence(char* sequence) {
  int i = 0;
  while(sequence[i] != '\0') {
    flash(sequence[i++]);
  }
  delay(DURATION_SEPARATOR_LETTERS);
}

void flash(char c) {
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_AUDIO, HIGH);
  if (c == '.') {
    delay(DURATION_DOT);
  } else if (c == '-') {
    delay(DURATION_DASH);
  }
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_AUDIO, LOW);
  delay(DURATION_SEPARATOR_DOTS);
}
