const int led = 13;
const int button = 2;
int val = 0;
int old_val = 0;
int state = 0;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}
void loop () {
  val = digitalRead(button);
  //이전 값을 저장해두고 이 값을 비교한다.
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1- state;
    delay(10);
  }
  old_val = val;
  if (state == 1)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}
