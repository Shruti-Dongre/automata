/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

}
void loop() {
  Serial.println("8 channel Servo test!");
  pwm.setPWM(0, 0, 300);//arm at front
  delay(1000);
//  pwm.setPWM(1, 0, 150);//arm at down
//  delay(1000);
//  pwm.setPWM(2, 0, 300);//open FRONT SERVO
//  delay(1000);
//  pwm.setPWM(2, 0, 390);//close FRONT SERVO
//  delay(1000);
  Serial.println("8 channel Servo test!");
  pwm.setPWM(0, 0, 600);//arm at back
  delay(1000);
//  pwm.setPWM(1, 0, 600);//arm at up
//  delay(1000);
//  pwm.setPWM(2, 0, 300);//open FRONT SERVO
//  delay(1000);
//  pwm.setPWM(2, 0, 390);//close FRONT SERVO  
//  delay(1000);
}
