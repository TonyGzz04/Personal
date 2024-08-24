  String m="El numero mayor es: ";

void setup(){
  Serial.begin(9600);
}

void loop(){
  String num=numeroMayor(70,50);
}

String numeroMayor(int x,int y){
  
  if (x>y){
  Serial.println(m + x);
  }

  else {
  Serial.println(m + y);
  }

}
