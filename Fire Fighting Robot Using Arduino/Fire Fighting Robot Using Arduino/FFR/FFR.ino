#define fire_sensorForward 8 
#define fire_sensorLeft 9      
#define fire_sensorRight  10      


int buzzer = 8;
int LED = 7;
int fire_detected_L;
int fire_detected_S;
int fire_detected_R;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(fire_sensorLeft, INPUT);
  pinMode(fire_sensorForward, INPUT);
  pinMode(fire_sensorRight, INPUT);
}

void loop()
{
  fire_detected_L = digitalRead(fire_sensorLeft);
  fire_detected_S = digitalRead(fire_sensorForward);
  fire_detected_R = digitalRead(fire_sensorRight);
  
  if (fire_detected_L == 1 || fire_detected_S ==1 || fire_detected_R == 1)
  {
    if(fire_detected_L == 1)
    {
       Serial.println("FIRE IS DETECTED IN LEFT SIDE!!!!! PLEASE TAKE ACTION TO PUT OFF FIRE");
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED, HIGH);
       delay(200);
       digitalWrite(LED, LOW);
       delay(200);
    }

    if(fire_detected_S == 1)
    {
       Serial.println("FIRE IS DETECTED IN FRONT SIDE!!!!! PLEASE TAKE ACTION TO PUT OFF FIRE");
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED, HIGH);
       delay(200);
       digitalWrite(LED, LOW);
       delay(200);
    }

    if(fire_detected_R == 1)
    {
       Serial.println("FIRE IS DETECTED IN RIGHT SIDE!!!!! PLEASE TAKE ACTION TO PUT OFF FIRE");
       digitalWrite(buzzer, HIGH);
       digitalWrite(LED, HIGH);
       delay(200);
       digitalWrite(LED, LOW);
       delay(200);
    }
   
  }

  else
  {
    Serial.println("NO FIRE DETECTED...");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
