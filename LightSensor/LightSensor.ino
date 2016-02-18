const int pinPhoto = A0;
int raw = 0;
int relay = 4;
void setup() {
  Serial.begin(9600);
  pinMode( pinPhoto, INPUT );
  pinMode( relay, OUTPUT );
}
void loop() {
  raw = analogRead( pinPhoto );
  if(raw < 500){
    Serial.println("Not enough light!");
    digitalWrite(relay, HIGH);
  } else {
    Serial.println("Normal light");
    digitalWrite(relay, LOW);
  }
  delay(1000);
}
