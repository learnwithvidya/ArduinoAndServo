#include <Servo.h>
Servo servo1;
int trigPin = 8;
int echoPin = 7;
long distance;
long duration;
 
void setup() 
{ 
  Serial.begin(9600);
 servo1.attach(12); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
 pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop() {
  ultra();
  servo1.write(0);
  if(distance <= 10){
    servo1.write(180);
    Serial.print("Obstacle Found at the distance : ");
    Serial.print(distance);
    Serial.print("\n");
    digitalWrite(LED_BUILTIN, HIGH);  
  }
    else
  {
    Serial.print("Obstacle not found \n");
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(50);
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }
