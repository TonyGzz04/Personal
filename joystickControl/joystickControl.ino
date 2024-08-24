

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x=analogRead(A0);
  int y=analogRead(A1);

  Serial.print("x = ");
  Serial.print(x);
  Serial.print("\n");
  Serial.print("y = ");
  Serial.println(y);
  delay(500);
}
