short ir[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
short angulo = 0;



void setup() {
  Serial.begin(115200);

  for (short i=0; i<12; i++){
    pinMode(ir[i],INPUT);
  }

}



void loop() {

  for (short i=0; i<13; i++){
    bool lectura=digitalRead(ir[i]);
    Serial.println(digitalRead(ir[8]));
  }
  
  

}
