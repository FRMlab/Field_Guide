/******************************************************************************
 * F_RMlab @ Waterloo School of Architecture
 * Code for irSensor and servo motor module
 * Grow-Op
 ******************************************************************************/

#define irLedPin PIND // IR Led on this pin
#define irSensorPin 2 // IR sensor on this pin
#include <Servo.h> // servo motor on this pin

Servo servo_1; 
int led = 12;

// defined constants:
int halfPeriod = 13; //one period at 38.5khZ is aproximately 26 microseconds
int cycles = 38; //26 microseconds * 38 is more or less 1 millisecond  

// defined initialization:
float pos = 0; // servo position
float inc = 5; // increment  
boolean go_down;

/******************************************************************************/
  
void setup()
{
  Serial.begin(9600);  
  Serial.println("Program Starting");
  pinMode(led, OUTPUT);
  servo_1.attach(10);
}

void loop(){
  irRead(irSensorPin, irLedPin); //display the results  
  int ir = digitalRead(irSensorPin);
  Serial.println(ir);  
  while (ir != 0){
    Serial.println(ir);  
    digitalWrite(led,HIGH);//trigger led 13
    ir = motor_inc(irSensorPin, irLedPin);
  }
  digitalWrite(led,LOW); //trigger-off led 13
}

// irRead: int int -> None
// Consumes int representing pin of infrared sensor pin (irSP) and
// infrared led pin (irLP) and produces None
// Effects: The function bangs a 38.5khZ waveform to an IR led connected to the
// triggerPin for 1 millisecond, and then reads the IR sensor pin to see if the reflected
// IR has been detected
// the irSP returns a zero if something is detected by the sensor, and a 1 otherwise

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

// motor_inc: None -> None
// Effects: The function increments the servo motor position by iteration based on
// direction of arm

int motor_inc(int irSP, int irLP)
{  
  if(pos >= 180 || pos <= 0){
    if(pos >= 180){
      go_down = false;
    }else{
      go_down = true;
    }
  } 
  if(go_down == true){
    Serial.println(go_down);
    pos += inc;
  }else{
    Serial.println(go_down);
    pos -= inc;
  }
  Serial.println(pos);
  servo_1.write(pos);
  delay(100);
  irRead(irSP, irLP);
  return digitalRead(irSP);
}
  


