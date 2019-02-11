// Setup Motor A (front and rear) pins
int enableA = 1;
int pinA1 = 3;
int pinA2 = 2;

// Setup Motor B (front and rear) pins
int enableB = 6;
int pinB1 = 5;
int pinB2 = 4;

//ultrasonic sensor
int trigger_pin = 2, echo_pin = 3; 
int time, distance;

void setup(){
  // The setup code goes here and runs once only
  // Configure the pin modes for each drive motor
   pinMode (enableA, OUTPUT);
   pinMode (pinA1, OUTPUT);
   pinMode (pinA2, OUTPUT);

   pinMode (enableB, OUTPUT);
   pinMode (pinB1, OUTPUT);
   pinMode (pinB2, OUTPUT);

   Serial.begin (9600);
   pinMode (trigger_pin, OUTPUT);
   pinMode (echo_pin, INPUT);
}

void loop(){
  digitalWrite (trigger_pin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigger_pin, LOW);
  time = pulseIn (echo_pin, HIGH);
  distance = (time * 0.034) / 2;
  
  if (distance <= 10)  {
     motorAon();
     motorBon();
     forward();
  }
  else  {
    void disableMotors();
  }
}
//void right (int duration) {
// motorAbackward();
// motorBforward();
// delay (duration);
//}
//
//void left (int duration) {
// motorAforward();
// motorBbackward();
// delay (duration);
//}
void motorAon(){
 digitalWrite (enableA, HIGH);
}

void motorBon(){
 digitalWrite (enableB, HIGH);
}

void forward (){
 motorAforward();
 motorBforward();
}

void motorAforward(){
 digitalWrite (pinA1, HIGH);
 digitalWrite (pinA2, LOW);
}

void motorBforward(){
 digitalWrite (pinB1, LOW);
 digitalWrite (pinB2, HIGH);
}

void disableMotors(){
 motorAoff();
 motorBoff();
}

void motorAoff(){
 digitalWrite (enableA, LOW);
}

void motorBoff(){
 digitalWrite (enableB, LOW);
}
