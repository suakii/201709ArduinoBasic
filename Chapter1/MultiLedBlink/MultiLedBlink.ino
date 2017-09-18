/*
*/

int del = 100;

void setup() {
        for (int i=4; i<=8; i++) {
                pinMode(i, OUTPUT); 
        }
}

void loop() {
        for (int i=4; i<=8; i++) {
                digitalWrite(i, HIGH); delay(del);             
                digitalWrite(i, LOW); delay(del);             
        }
 
        for (int i=7; i>=5; i--) {
                digitalWrite(i, HIGH);   
                delay(del);              
                digitalWrite(i, LOW);    
        }
}
