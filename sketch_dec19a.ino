#define FLAME_SENSOR_PIN 2
#define BUZZER_PIN 3
#define RELAYMODULE_PIN 4
#define WATER_SPRINKLER_START_AT 2000  //2 seconds before the pump starts
#define WATER_SPRINKLER_TIME 10000      //10 seconds of run time of water sprinkler

unsigned long previousTime = millis();

void setup() 
{
  pinMode(RELAYMODULE_PIN, OUTPUT);
  pinMode(FLAME_SENSOR_PIN, INPUT);  
}

void loop() 
{
  //If there is fire then the sensor value will be LOW else the value will be HIGH
  int sensorValue = digitalRead(FLAME_SENSOR_PIN);

  //There is fire
  if (sensorValue == LOW)
  {
    analogWrite(BUZZER_PIN, 50);                          //Turns on the buzzer

    if (millis() - previousTime > WATER_SPRINKLER_START_AT)  //the pump will wait for few seconds before sprinkler can be started once fire is detected.
    {
      digitalWrite(RELAYMODULE_PIN, LOW);                       //Relay is low level triggered relay so we need to write LOW to switch on the light 
      delay(WATER_SPRINKLER_TIME);                           //this will keep the sprinkler on for the given time.
    }
  }
  else
  {
    analogWrite(BUZZER_PIN, 0);    
    digitalWrite(RELAYMODULE_PIN, HIGH); 
    previousTime = millis();  
  }
} 