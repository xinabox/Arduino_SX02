/*
	This is a library for the SX02 
	Analog IN -	Max Input 3.3V

	The board uses I2C for communication.
	
	The board communicates with one I2C devices:
	- ADC081C021
	
	Data Sheets:
	ADC081C021 - http://www.ti.com/lit/ds/symlink/adc081c021.pdf
*/

#include <arduino-SX02.h>
#include <math.h>

/********************************************************
 	Constructor
*********************************************************/
xSX02::xSX02(){
	voltage = 0.0;
	ADC_I2C_ADDRESS = 0x55;
}

xSX02::xSX02(uint8_t addr){
	voltage = 0.0;
	ADC_I2C_ADDRESS = addr;
}

/********************************************************
 	Configure Sensor
*********************************************************/
void xSX02::begin(){
	xCore.write8(ADC_I2C_ADDRESS, ADC_REG_CONF, ADC_CONF_CYC_TIME_256); 
}

/********************************************************
 	Read Data from ADC081C021
*********************************************************/
void xSX02::poll(){
	readVoltage();
}

/********************************************************
 	Request ADC voltage
*********************************************************/
float xSX02::getVoltage(){
	return voltage;
}

/* Private Functions */
 
/********************************************************
 	Read Voltage
*********************************************************/
void xSX02::readVoltage(){
	uint16_t data;
	
	data = xCore.read16(ADC_I2C_ADDRESS, ADC_REG_RESULT);
	
	a = (uint8_t)((data & 0xFF00) >> 8);
	b = (uint8_t)((data & 0x00FF) >> 0);
	
	voltage = ((((a & 0x0F)*256) + (b & 0xF0))/0x10)*(3.3/256);
}





