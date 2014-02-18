
// elementary cellular automata

int cell_length = 101;
int cell_center = (cell_length-1)/2 + 1 ;
String[]array_0 = new String [cell_length];
String[]array_1 = new String [cell_length];

//---------------------------------------------------------------------------------------
void setup(){
  initialize();
} 
 
void draw(){
  println();
  cell_automatate();
  transfer();  
}  

//---------------------------------------------------------------------------------------  
//1.
void initialize(){
  //println();
  for(int i=0; i<cell_length; i++){
    if (i == cell_center-1){
      array_0[i] = "1";
      print(array_0[i]);
    }
    else{
      array_0[i] = " ";
      print(array_0[i]);
    }
  }
}

//---------------------------------------------------------------------------------------
//2.
void cell_automatate(){
  for (int i=0; i<cell_length; i++){
    if(i != 0 && i != (cell_length-1)){
      array_1[i] = rules(array_0[i-1], array_0[i], array_0[i+1]);
      print (array_1[i]);
    }
    else if(i == 0){
      array_1[i] = rules(array_0[cell_length -1], array_0[i], array_0[i+1]);
      print (array_1[i]);
    }
    else{
      array_1[i] = rules(array_0[i-1], array_0[i], array_0[0]);
      print (array_1[i]);
    }
  }
}

//---------------------------------------------------------------------------------------
//3.
void transfer(){
  for (int i=0; i<cell_length; i++){
    array_0[i] = array_1[i];
  }
}

//---------------------------------------------------------------------------------------
//4. 
String rules (String a, String b, String c) {
    //Serpinski triangle 
    /*
    if (a == "1" && b == "1" && c == "1") return "1";
    if (a == "1" && b == "1" && c == " ") return "1";
    if (a == "1" && b == " " && c == "1") return " ";
    if (a == "1" && b == " " && c == " ") return "1";
    if (a == " " && b == "1" && c == "1") return "1";
    if (a == " " && b == "1" && c == " ") return " ";
    if (a == " " && b == " " && c == "1") return "1";
    if (a == " " && b == " " && c == " ") return " ";
    else
      return " ";
    */
    
    // Randomness!
    
    if (a == "1" && b == "1" && c == "1") return "1";
    if (a == "1" && b == "1" && c == " ") return "1";
    if (a == "1" && b == " " && c == "1") return "1";
    if (a == "1" && b == " " && c == " ") return " ";
    if (a == " " && b == "1" && c == "1") return " ";//
    if (a == " " && b == "1" && c == " ") return " ";
    if (a == " " && b == " " && c == "1") return " ";
    if (a == " " && b == " " && c == " ") return "1";
    else
      return " ";
    
  }

  
      
