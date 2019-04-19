#include <Arduino.h>


/*This example for ADXL356B default,*/


#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
  #define SERIAL SerialUSB
  #define SYS_VOL   3.3
#else
  #define SERIAL Serial
  #define SYS_VOL   5
#endif

float cali_data_xy;
float cali_data_z;
int16_t scale;

/*This sketch supports ADXL356B/C module.*/

/*You can switch the range to ±10g/±20g for adxl356B,±10g/±40g for adxl356C.*/
/*If you use another option,such as 10g or 40g,modify this value is OK.*/
#define MODUEL_RANGE           20

#define MODULE_VOL             1.8

#define CALI_BUF_LEN           15
#define CALI_INTERVAL_TIME     250

float cali_buf_xy[CALI_BUF_LEN];
float cali_buf_z[CALI_BUF_LEN];

#define XY_PIN   A0
#define Z_PIN    A1

float deal_cali_buf(float *buf)
{
	float cali_val = 0;
	
	for(int i = 0;i < CALI_BUF_LEN;i++)
	{
		cali_val += buf[i];
	}
	cali_val = cali_val/CALI_BUF_LEN;
	return (float)cali_val;
}


void calibration(void)
{
	SERIAL.println("Please Place the module horizontally!");
	delay(1000);
	SERIAL.println("Start calibration........");
	
	for(int i=0;i<CALI_BUF_LEN;i++)
	{
		cali_buf_xy[i] = analogRead(XY_PIN);;
		cali_buf_z[i] = analogRead(Z_PIN);
		delay(CALI_INTERVAL_TIME);
	}
	cali_data_xy =  deal_cali_buf(cali_buf_xy);
	cali_data_z =  (float)deal_cali_buf(cali_buf_z);
	SERIAL.println("Calibration OK!!");
	scale = (float)1000 / (cali_data_z - cali_data_xy);
	cali_data_z -= (float)980 / scale;
	SERIAL.println(cali_data_xy);
	SERIAL.println(cali_data_z);
	SERIAL.println(scale);
	
}



void AccMeasurement(void)
{
	int16_t val_xy = 0;
	int16_t val_z = 0;
	val_xy = analogRead(XY_PIN);
	val_z = analogRead(Z_PIN);
	
	SERIAL.print("Raw data xy  = ");
	SERIAL.println(val_xy);
	SERIAL.print("Raw data z  = ");
	SERIAL.println(val_z);
	SERIAL.println(" ");
	
	val_xy -= cali_data_xy;
	val_z -= cali_data_z;
	SERIAL.print("x or y position acc is ");
	SERIAL.print(val_xy * scale / 1000.0);
	SERIAL.println(" g ");
	SERIAL.print("z position acc is ");
	SERIAL.print(val_z * scale / 1000.0);
	SERIAL.println(" g ");
	SERIAL.println(" ");
	SERIAL.println(" ");
	SERIAL.println(" ");
	delay(1000);
}

void setup()
{
	SERIAL.begin(115200);
	#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
	analogReadResolution(12);
	#endif
	calibration();
	SERIAL.print("Scale = ");
	SERIAL.println(scale);
	
}



void loop()
{
	AccMeasurement();
}
