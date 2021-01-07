#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 7, 6, 5, 4);

int trigPin = 11;
int echoPin = 10;
int duration;
float cm, inches;

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
  
  Serial.print(inches,1);
  Serial.print("in, ");
  Serial.print(cm,1);
  Serial.print("cm");
  Serial.println();
  
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Dist:"); // Prints string "Distance" on the LCD
  lcd.print(cm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("Dist:");
  lcd.print(inches);
  lcd.print("inch");
  delay(10);
  
  delay(200);
}
  