// EX 2_2 Pin Change Interrupt
// 1) Arduino Programming Version

const int buttonPin = 8;   // D8 - PB0
const int ledPin = 13;     // D13 - PB5
volatile bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // pull-up
}

void loop() {
  static int lastState = HIGH;
  int currentState = digitalRead(buttonPin);

// detect HIGH → LOW transition
  if (lastState == HIGH && currentState == LOW) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }

  lastState = currentState;
  delay(10);
}
