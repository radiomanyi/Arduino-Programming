int buttonPin = 2;
int ledPin = 3;
void setup() {
  // setup pin modes
  pinMode(ledPin, OUTPUT);                  
  pinMode(buttonPin, INPUT_PULLUP);
}
void loop() {
  // read state of buttonPin and store it as the buttonState variable
  int buttonState = digitalRead(buttonPin);
  // write the value of buttonState to ledPin
  digitalWrite(ledPin, buttonState);
}