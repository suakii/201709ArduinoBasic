import processing.serial.*;
int lf = 10; // Linefeed in ASCII
String myString = null;
Serial myPort; // Serial port you are using
float num;
void setup() {
  background(255,255,255);
  size(600,600);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[4], 9600); 
}
void draw() {
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil(lf);
    if (myString != null) {
      num=float(myString); // Converts and prints float
      background(255,255,255);
      fill(#ffcb01);
      ellipse(width/2,height/2,num/2,num/2);
    }
  }
  myPort.clear();
}
