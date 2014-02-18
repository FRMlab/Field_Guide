
// set_direction
// code sets dir variable to 1 - 4 then 
// motor_inc changes pos based on dir
// and returns ir variable
void set_direction(int ir){
  if(ir > 175){ //if sensor is active
    digitalWrite(led,HIGH);//trigger led 13
    while(pos > 0){ //go to 0 = top
      dir = 1;
      ir = motor_inc(irSensorPin);
    }
    dir = 2;//stay at top = 0
    ir = motor_inc(irSensorPin);
    inc = init_inc;   
  }else{
    digitalWrite(led,LOW);//trigger led 13
    if(pos < 180){ // go to 180 = bottom
      dir = 3;
      ir = motor_inc(irSensorPin);
    }
    dir = 4;//stay at bottom = 180
    ir = motor_inc(irSensorPin);
    inc = init_inc;
  }
} 
