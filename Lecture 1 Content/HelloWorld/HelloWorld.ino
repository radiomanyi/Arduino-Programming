void setup() {                
  pinMode(13, OUTPUT);       //setup pin 13 as an output
}

void loop() {
  digitalWrite(13, HIGH);    // turn the LED on (HIGH outputs 5V)
  delay(500);                // wait for 500 milliseconds
  digitalWrite(13, LOW);     // turn the LED off (LOW outputs 0V)
  delay(500);                // wait for 500 milliseconds
}