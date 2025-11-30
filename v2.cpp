#include <Servo.h>

 int trig = 9;  
 int echo = 10;  
 int servo = 11; 
Servo pro;
long time;       // thời gian
int d;          //khoảng cách
bool open = false;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pro.attach(servo);
  pro.write(0);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  time = pulseIn(echo, HIGH);
  d = time * 0.034 / 2 ;

  Serial.print("Khoang cach: ");
  Serial.print(d);
  Serial.println(" cm");

if (d > 0 && d < 15 && open == false) {

    for (int pos = 0; pos <= 90; pos += 2) { 
      pro.write(pos);              
      delay(15); 
    }
    open = true; 
    delay(1000); 
  } 
  
  else if ((d == 0 || d >= 15) && open == true) {
    
    for (int pos = 90; pos >= 0; pos -= 2) { 
      pro.write(pos);              
      delay(15); 
    }
    
    open = false; 
  }
  delay(1000); 
}
