   /*     
    On Class Test
    by: Yi Ping
    SparkFun Electronics
    created on 12/2/2020
    */
    
    int ledPin = 6;  // LED is attached to digital pin 6
    unsigned char x=0;  // variable to be updated by the interrupt

    //variables to keep track of the timing of recent interrupts
    unsigned long button_time = 0;  
    unsigned long last_button_time = 0; 
    
    void setup() {                
      //enable interrupt 0 (pin 2,3) which is connected to a button
      //jump to the increment function on falling edge
      pinMode(ledPin, OUTPUT);
      pinMode(2, INPUT_PULLUP);
      pinMode(3, INPUT_PULLUP);
      attachInterrupt(digitalPinToInterrupt(2), increment, RISING);
      attachInterrupt(digitalPinToInterrupt(3), decrement, RISING);
      Serial.begin(9600);  //turn on serial communication
    }
    
    void loop() {      
      Serial.println(x, DEC); //print x to serial monitor
      analogWrite(ledPin,x);      
    }

    // Interrupt service routine for interrupt 0
    void increment() {
      button_time = millis();
    //check to see if increment() was called in the last 250 milliseconds
      if (button_time - last_button_time > 250)
      {
        x=x+30;      
        last_button_time = button_time;
      }
    }

 void decrement() {
      button_time = millis();
      //check to see if increment() was called in the last 250 milliseconds
      if (button_time - last_button_time > 250)
      {
        if(x>10)
        {x=x-30;}
        last_button_time = button_time;
      }
    }
