#define fire_sensorForward 8 
#define fire_sensorLeft 9      
#define fire_sensorRight  10      

#define LeftMotor1 2       
#define LeftMotor2 3       
#define RightMotor1 4       
#define RightMotor2 5       

int buzzer = 6;
int LED = 7;
int fire_detected_L;
int fire_detected_S;
int fire_detected_R;
boolean fire = false;

void setup()
{
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
}


void loop()
{
  fire_detected_L = digitalRead(fire_sensorLeft);
  fire_detected_S = digitalRead(fire_sensorForward);
  fire_detected_R = digitalRead(fire_sensorRight);
  
  
    if(fire_detected_L == 1)
    {
       Serial.println("FIRE IS DETECTED IN LEFT SIDE!!!!! PLEASE TAKE ACTION TO PUT OFF FIRE");
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED, HIGH);
       delay(200);
       digitalWrite(LED, LOW);
       delay(200);
    }

    else if(fire_detected_S == 1)
    {
       Serial.println("FIRE IS DETECTED IN FRONT SIDE!!!!! PLEASE TAKE ACTION TO PUT OFF FIRE");
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED, HIGH);
       delay(200);
       digitalWrite(LED, LOW);
       delay(200);
    }

    else if(fire_detected_R == 1)
    {
       Serial.println("FIRE IS DETECTED IN RIGHT SIDE!!!!! PLEASE TAKE ACTION TO PUT OFF FIRE");
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED, HIGH);
       delay(200);
       digitalWrite(LED, LOW);
       delay(200);
    }
   
    else if(fire_detected_L == 1 && fire_detected_R == 1 && fire_detected_S == 1)
    {
       Serial.println("FIRE IS DETECTED IN ALL SIDES!!!!! PLEASE TAKE ACTION TO PUT OFF FIRE");
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED, HIGH);
       delay(200);
       digitalWrite(LED, LOW);
       delay(200);
    }

  else
  {
    Serial.println("NO FIRE DETECTED...");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, LOW);
  }
  delay(1000);


  
 
    if (digitalRead(fire_sensorLeft) ==1 && digitalRead(fire_sensorRight)==1 && digitalRead(fire_sensorForward) ==1) 
    {
    
    digitalWrite(LeftMotor1, HIGH);
    digitalWrite(LeftMotor2, HIGH);
    digitalWrite(RightMotor1, HIGH);
    digitalWrite(RightMotor2, HIGH);
    }
    
    else if (digitalRead(fire_sensorForward) ==0) 
    {
   
    digitalWrite(LeftMotor1, HIGH);
    digitalWrite(LeftMotor2, LOW);
    digitalWrite(RightMotor1, HIGH);
    digitalWrite(RightMotor2, LOW);
    fire = true;
    }
    
    else if (digitalRead(fire_sensorLeft) ==0) 
    {
    
    digitalWrite(LeftMotor1, HIGH);
    digitalWrite(LeftMotor2, LOW);
    digitalWrite(RightMotor1, HIGH);
    digitalWrite(RightMotor2, HIGH);
    }
    
    else if (digitalRead(fire_sensorRight) ==0) 
    {
    
    digitalWrite(LeftMotor1, HIGH);
    digitalWrite(LeftMotor2, HIGH);
    digitalWrite(RightMotor1, HIGH);
    digitalWrite(RightMotor2, LOW);
    }
    
delay(300); 
 
}
