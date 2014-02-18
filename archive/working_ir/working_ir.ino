/******************************************************************************
 * F_RMlab @ Waterloo School of Architecture
 * Code for irSensor and servo motor module
 * Grow-Op
 ******************************************************************************/

#define irLedPin PIND          // IR Led on this pin
#define irSensorPin 2       // IR sensor on this pin
#include <Servo.h> 

Servo servo_1;  // create servo object to control a servo 

int led = 13;

int halfPeriod = 13; //one period at 38.5khZ is aproximately 26 microseconds
int cycles = 38; //26 microseconds * 38 is more or less 1 millisecond
  
float pos = 0;    // variable to store the servo position 
float it = 0.25;   
  
void setup()
{
  Serial.begin(9600);  
  Serial.println("Program Starting");
  
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);  
  servo_1.attach(10);
}

void loop(){  
  irRead(irSensorPin, irLedPin); //display the results
  Serial.println (digitalRead(irSensorPin));
  delay(100); //wait for the string to be sent
  
  while (digitalRead(irSensorPin) != 0){
    digitalWrite(led,HIGH);//trigger led 13
    delay(500);
  }
  digitalWrite(led,LOW); //trigger-off led 13
}

/******************************************************************************
 * This function can be used with a panasonic pna4602m ir sensor
 * it returns a zero if something is detected by the sensor, and a 1 otherwise
 * The function bit bangs a 38.5khZ waveform to an IR led connected to the
 * triggerPin for 1 millisecond, and then reads the IR sensor pin to see if
 * the reflected IR has been detected
 ******************************************************************************/

void irRead(int irSP, int irLP)
{  
  for (int i=0; i <= cycles; i++)
  { 
    //digital irled signal sent
    digitalWrite(irLP, HIGH);  
    delayMicroseconds(halfPeriod);
    digitalWrite(irLP, LOW); 
    delayMicroseconds(halfPeriod - 1);     // - 1 to make up for digitaWrite overhead    
  }
}
