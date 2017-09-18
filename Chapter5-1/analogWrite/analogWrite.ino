int ledPin = 6;      // LED connected to digital pin 6
int val = 0;         // variable to store the read value
   
void setup()
{
  pinMode(ledPin, OUTPUT);   // sets the pin as output
}
   
void loop()
{
  analogWrite(ledPin, val);  // analogWrite values from 0 to 255
  delay(5);
     
  val += 1;
   
  if(val >= 256)
    val = 0;
}
