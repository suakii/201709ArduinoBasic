int analogPin = 0;
int val = 0;
int R1 = 10000;
int R2 = 10000;
float Vin = 0.0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  val = analogRead(analogPin);
  Vin = (R1 + R2) / R2 * val * 5 / 1023.0;
  Serial.println(Vin);
  delay(500)
}
