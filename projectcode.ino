#include "HX711.h"
#include <Wire.h>
#include <Servo.h>
Servo myservo;
// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = A1;
const int LOADCELL_SCK_PIN = A0; 
int servoPin = 8;
float berat =123;
HX711 scale;
void setup() {
  Serial.begin(57600);
  Serial.println("Make sure there is no load okay?");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(96.3);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare(50);                        // reset the scale to 0
  Serial.println("Go weight it");
  myservo.attach(8);
}

void loop() {
 // Serial.print("Weight");
  float berat= scale.get_units(25);
  if(berat<=0.1)
  {
  berat=0.0;
  
  //berat=567; // dummy for testing ONLY ***************
 // berat=567; // dummy for testing ONLY ***************
 
  }
  Serial.print("TestWt= " );
  Serial.println(berat);
  
  if(berat<500)
  {
     Serial.print(" Weight<500; g="); 
     Serial.print(berat); 
  
  }
  if(berat>=500)
  {
      Serial.print(" Weight>=500; g="); 
     Serial.print(berat);  
 
  }
  // scale.power_down();
  delay(10);
  // scale.power_up();
  
  if(berat<500) {
    Serial.println("  Servo=180"); 
    Serial.println(); 
    myservo.write(180);
    delay(10);
  }
  else {
     Serial.println("  Servo=000");
       Serial.println(); 
    myservo.write(0);
    delay(10);
  }
}
