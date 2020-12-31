// pin definitions
int ledPin = 3;

// global variables
int rampTime = 2;

void setup() {
  // setup pin modes
  pinMode(ledPin, OUTPUT);
  //initialise serial port
  Serial.begin(9600);
}

void loop() {  
  // ramp LED brightness up to max
  for(int i = 0; i<256; i++)
  {
    analogWrite(ledPin, i);
    delay(rampTime);
    Serial.println(i);
  }

  // ramp LED brightness down to 0
  for(int i = 255; i>0; i--)
  {
    analogWrite(ledPin, i);
    delay(rampTime);
    Serial.println(i);
  }