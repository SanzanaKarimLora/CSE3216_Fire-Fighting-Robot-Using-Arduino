
#include <Servo.h>
Servo myservo;
 
int pos = 0;    
boolean fire = false;

#define fire_sensorForward 8 
#define fire_sensorLeft 9      
#define fire_sensorRight  10      

#define LeftMotor1 2       
#define LeftMotor2 3       
#define RightMotor1 4       
#define RightMotor2 5  

#define pump 12

int buzzer = 6;
int LED = 7;

void setup()
{

  LeftMotor1.setSpeed(170);
  LeftMotor2.setSpeed(170);
  RightMotor1.setSpeed(170);
  RightMotor2.setSpeed(170);
  
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(fire_sensorLeft, INPUT);
  pinMode(fire_sensorForward, INPUT);
  pinMode(fire_sensorRight, INPUT);

  
  pinMode(LeftMotor1, OUTPUT);
  pinMode(LeftMotor2, OUTPUT);
  pinMode(RightMotor1, OUTPUT);
  pinMode(RightMotor2, OUTPUT);

  pinMode(pump,OUTPUT);

  myservo.attach(11);
  myservo.write(90);
}

void put_off_fire()
{
    delay (500);
 
    digitalWrite(LeftMotor1, HIGH);
    digitalWrite(LeftMotor2, HIGH);
    digitalWrite(RightMotor1, HIGH);
    digitalWrite(RightMotor2, HIGH);
    
    digitalWrite(pump, HIGH);
    delay(500);
    
    for (pos = 50; pos <= 130; pos += 1) { 
           myservo.write(pos); 
           delay(10);  
    }
  
    for (pos = 130; pos >= 50; pos -= 1) { 
           myservo.write(pos); 
           delay(10);
    }
  
    digitalWrite(pump,LOW);
    myservo.write(90);
  
    fire=false;
}

void loop()
{

 
    if (digitalRead(fire_sensorLeft) ==1 && digitalRead(fire_sensorRight)==1 && digitalRead(fire_sensorForward) ==1) 
    {

      digitalWrite(buzzer, LOW);
      digitalWrite(LED,LOW);
    
      digitalWrite(LeftMotor1, HIGH);
      digitalWrite(LeftMotor2, HIGH);
      digitalWrite(RightMotor1, HIGH);
      digitalWrite(RightMotor2, HIGH);
    }
    
    else if (digitalRead(fire_sensorForward) ==0) 
    {

       digitalWrite(buzzer, HIGH);
       digitalWrite(LED,HIGH);
   
       digitalWrite(LeftMotor1, HIGH);
       digitalWrite(LeftMotor2, LOW);
       digitalWrite(RightMotor1, HIGH);
       digitalWrite(RightMotor2, LOW);
       fire = true;
    }
    
    else if (digitalRead(fire_sensorLeft) ==0) 
    {
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED,HIGH);
      
       digitalWrite(LeftMotor1, HIGH);
       digitalWrite(LeftMotor2, HIGH);
       digitalWrite(RightMotor1, HIGH);
       digitalWrite(RightMotor2, LOW);
    
    }
    
    else if (digitalRead(fire_sensorRight) ==0) 
    {
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED,HIGH);
      
      digitalWrite(LeftMotor1, HIGH);
      digitalWrite(LeftMotor2, LOW);
      digitalWrite(RightMotor1, HIGH);
      digitalWrite(RightMotor2, HIGH);
    
    }
    
  delay(300);

 
     while (fire == true)
     {
      put_off_fire();
     } 
 
}
