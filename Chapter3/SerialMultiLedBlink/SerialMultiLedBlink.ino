/*
*/

int del = 100;
char buffer[5];//pin 4,5,6,7,8
void setup() 
{
        for (int i=4; i<=8; i++) {
                pinMode(i, OUTPUT); //핀 모드 설정을 한다.
        }
        Serial.begin(9600);//시리얼 통신을 위해 속도를 설정한다.
}
 
void loop() {
    if (Serial.available()) { //컴퓨터에서 보내온 자료가 있다면
                int index = 0; 
                delay(100);
                int numChar = Serial.available();//몇 글자 인지 읽는다.
                Serial.print("numChar: ");//디버깅을 위해 컴퓨터로 전송해준다.
                Serial.println(numChar);//받는 문자를 출력한다.
                while (numChar--) {//버퍼에 해당 문자열을 입력한다.
                        buffer[index++] = Serial.read();
                }
    showLED(buffer, index);//사용자 정의 함수를 호출한다.
  }
}
void showLED(char* data, int dataSize) //문자열 배열과, 사이즈를 받아서 출력
{
  for (int i = 0; i < dataSize; i++) {
    if (data[i] == '1')
      digitalWrite(i+4, HIGH);//해당 문자 값에 따라 LED를 켜고 끈다.
    else
      digitalWrite(i+4, LOW);
  }
 
}
