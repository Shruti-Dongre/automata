int trigger_pin = 9, echo_pin = 8; 
int time, distance; 

void setup ( )
{
  Serial.begin (9600);
  pinMode (trigger_pin, OUTPUT);
  pinMode (echo_pin, INPUT);
}

void loop ( )
{
  digitalWrite (trigger_pin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigger_pin, LOW);
  time = pulseIn (echo_pin, HIGH);
  distance = (time * 0.034) / 2;   

  if (distance <= 10)
  {
    Serial.println (" Door Open ");
    Serial.print (" Distance= ");
    Serial.println (distance);
    delay (100);
  }

  else
  {
    Serial.println (" Door closed ");
    Serial.print (" Distance= ");              
    Serial.println (distance);
    delay (100);        
  }
 }
