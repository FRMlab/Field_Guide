
// motor_inc: None -> None
// Effects: The function increments the servo motor position by iteration based on
// direction of arm

int motor_inc(int irSP)
{  
  if(dir == 3){ // go to bottom
    pos += inc;
  }else if (dir == 1){ // go to top
    pos -= inc;
  }else{ // stay
     // do nothing
  }
  //servo_2.write(pos);
  servo_1.write(pos);
  servo_2.write(pos);
  servo_3.write(pos);
  servo_4.write(pos);
  delay(30);
  return analogRead(irSP);
}
