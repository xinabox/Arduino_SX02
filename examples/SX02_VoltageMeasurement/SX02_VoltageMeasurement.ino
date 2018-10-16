/*************************************************************
  This is an example for the SX02
  Analog IN - Max Input 3.3V
  
  You can buy one on our store!
  -----> https://xinabox.cc/products/SX02/
  
  This example measures the input voltage on the SX02
  and displays it on the Serial Monitior
    
  The sensor communicates over the I2C Bus.

*************************************************************/

#include <xCore.h>
#include <arduino-SX02.h>

xSX02 SX02;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

   // Set the I2C Pins for CW01
	#ifdef ESP8266
	  Wire.pins(2, 14);
	  Wire.setClockStretchLimit(15000);
  #endif
  // Start the I2C Communication
  Wire.begin();

  // Start the ☒CHIP Sensor
  SX02.begin();
  
  Serial.println("==============================");
  Serial.println("   SX02 Voltage Measurement");
  Serial.println("==============================");
}

void loop() {

  float voltage = 0;

  SX02.poll();

  voltage = SX02.getVoltage();

  // Print Voltage 
  Serial.print("Voltage = ");
  Serial.print(voltage,3);
  Serial.println(" V");
  Serial.println();

  delay(1000);
}
