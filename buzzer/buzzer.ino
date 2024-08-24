const int buzzer=12;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,12);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer,440,1000);
}
