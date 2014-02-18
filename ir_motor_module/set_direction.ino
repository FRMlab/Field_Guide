/******************************************************************************
  Define variables for hardware.
  1. Define MUX control pins on board.
  2. Define servo motor on this pin.
  Define variables for code.
  1. Global variables
 ******************************************************************************/
 
// set_direction
// code sets dir variable to 1 - 4 then 
// motor_inc changes pos based on dir
// and returns ir variable
void set_direction(int ir){
  if(ir > DIST_VAL){ //if sensor is active
    digitalWrite(led,HIGH);//trigger led 13
    if(pos > 0){ //go to 0 = top
      dir = 1;
      pos = motor_inc(pos);
    }else{
    dir = 2;//stay at top = 0
    pos = motor_inc(pos);
    }
  }else{
    digitalWrite(led,LOW);//trigger led 13
    if(pos < 180){ // go to 180 = bottom
      dir = 3;
      pos = motor_inc(pos);
    }else{
      dir = 4;//stay at bottom = 180
      pos = motor_inc(pos);
    }
  }
  //ir = analogRead(irSensorPin);
} 
