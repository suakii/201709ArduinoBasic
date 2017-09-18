import processing.serial.*;
int lf = 10;
Serial myPort;
String myString;
int value;
  void setup() {
  size(600, 600);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[4], 9600);
}
void draw() {
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil(lf);
    if (myString != null) {
      myString = trim(myString);
      value = int(myString);
      println(value);
      background(255);
      fill(0);
      rect(value*5, value*5, 100, 100);
  }
}
