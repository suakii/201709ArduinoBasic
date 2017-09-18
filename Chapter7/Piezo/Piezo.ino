const int speakerPin = 9;
const int sensorPin = 0;
void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(sensorPin);
  int frequency = map(sensorValue, 0, 1023, 100, 5000);
  int duration = 250;
  tone(speakerPin, frequency, duration);//스피커핀, 주파수, 재생시간(milli second)
  Serial.println(sensorValue);
  delay(100);
}
