const char HEADER = 'H';
const int TOTAL_BYTES = 6;

const char LED_TAG = 'L';

const int LED1 = 4;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 7;

const int ON = 1;
const int OFF = 0;
 
const int LED1_pin = 4;
const int LED2_pin = 5;
const int LED3_pin = 6;
const int LED4_pin = 7;

int led_port = 0;
int button_state = 0;


void setup() {
  Serial.begin(9600);
  pinMode(LED1_pin,OUTPUT);
  pinMode(LED2_pin,OUTPUT);
  pinMode(LED3_pin,OUTPUT);
  pinMode(LED4_pin,OUTPUT);

  digitalWrite(LED1_pin, HIGH);
  digitalWrite(LED2_pin, HIGH);
  digitalWrite(LED3_pin, HIGH);
  digitalWrite(LED4_pin, HIGH);
  delay(100);
  digitalWrite(LED1_pin, LOW);
  digitalWrite(LED2_pin, LOW);
  digitalWrite(LED3_pin, LOW);
  digitalWrite(LED4_pin, LOW);
}

void loop() 
{
  if(Serial.available() >= TOTAL_BYTES)
  {
    if(Serial.read() == HEADER)
     {
       char tag = Serial.read();
       if(tag == LED_TAG)
       {
         int led = Serial.read();
         led = led + Serial.read();
         int button = Serial.read();
         button = button + Serial.read();
         if(led == LED1 && button == ON)
         {
           led_port = LED1_pin;
           button_state = HIGH;
         }
         else if(led == LED1 && button == OFF)
         {
           led_port = LED1_pin;
           button_state = LOW;
         }
         else if(led == LED2 && button == ON)
         {
           led_port = LED2_pin;
           button_state = HIGH;
         }
         else if(led == LED2 && button == OFF)
         {
           led_port = LED2_pin;
           button_state = LOW;
         }
         else if(led == LED3 && button == ON)
         {
           led_port = LED3_pin;
           button_state = HIGH;
         }
         else if(led == LED3 && button == OFF)
         {
           led_port = LED3_pin;
           button_state = LOW;
         }
         else if(led == LED4 && button == ON)
         {
           led_port = LED4_pin;
           button_state = HIGH;
         }
         else if(led == LED4 && button == OFF)
         {
           led_port = LED4_pin;
           button_state = LOW;
         }
         digitalWrite(led_port, button_state);
       } // (tag == LED_TAG)
     }
  }
  
  delay(100);
  
}
