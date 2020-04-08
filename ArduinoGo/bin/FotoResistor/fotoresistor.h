/******************************************************************************
* Nom del fitxer: fotoresistor.h					     			    	  *
* Data: 25/11/2013							      							  * 
* Autor: Cristian Soriano, Chenglong Zou					      			  *
* Descripció: Capçalera per llegir el fotorresistor					  		  *
******************************************************************************/

#include "Arduino.h"

#define FOTORESISTOR_LIB_VERSION 0.1
#define HUMITATEMPERATURA_OK				 0
#define HUMITATEMPERATURA_ERROR_TIMEOUT		-1

const float ADCres_fotoresistor = 1023.0;
const float luxRel = 500.0;
const float RL = 10.0;
const float Vref = 5.0;


class FotoResistor
{
	public:
		uint8_t pin;
		FotoResistor(uint8_t _pin);
    	int read();
		int lux;
};
