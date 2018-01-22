// I2C interface by default

#include "Wire.h"
#include "accelerometer_setup.h"

// cmment out if not using neopixel
//#include "neopixel_setup.h"


//int steps, flag;// , flag_movement;
//float threshold = 1200;
unsigned long startTime = millis();
int interval = 10000;//600000;
int flag_movement = 0;


void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  // comment out if not using accelerometer
  if (myIMU.begin() != IMU_SUCCESS)
  {
    Serial.println("Failed accelerometer setup.");
    while(1);
  }

  // comment out if not using neopixel
  //  strip.begin();
  //  strip.show();  
}


void loop()
{
  
acceleration_3D();

float M = magnitude_3D(acceleration[x], 
                       acceleration[y], 
                       acceleration[z]);

step_counter(M);


Serial.print(acceleration[x]);       
Serial.print("\t");
Serial.print(acceleration[y]);        
Serial.print("\t");
Serial.print(acceleration[z]);        
Serial.print("\t");
Serial.print(M);  
Serial.print("\t");
Serial.println(steps * 100);    
delay(200);
}

