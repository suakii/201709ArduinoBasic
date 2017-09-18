import processing.serial.*;
Serial myPort;
int xPos = 1;
void setup () {
  size(400, 300);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.bufferUntil('\n');
  background(0);
}
void draw () {
}
void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    float inByte = float(inString);
    fill(0);
    noStroke();
    rect(0, 0, 70, 50);
    fill(127, 34, 255);
    text(inString + " C" , 65, 25);
    stroke(127,34,255);
    line(xPos, height, xPos, height - inByte*7);
    if (xPos >= width) {
      xPos = 0;
      background(0);
    }
    else {
      xPos++;
    }
  }
}
