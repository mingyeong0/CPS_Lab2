// EX 2.1 External Interrupt (Button on INT0)
// 1) Arduino Programming Version

const int buttonPin = 2; // D2 - INT0
const int ledPin = 13;   // D13 - LED

volatile bool ledState = LOW;

// ISR function
void toggleLED() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // INPUT_PULLUP - INTO pin
  // FALLING edge
  attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, FALLING);
}

void loop() {
}
