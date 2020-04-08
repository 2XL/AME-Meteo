/******************************************************************************
* Nom del fitxer: fotoresistor.cpp					     			    	  *
* Data: 25/11/2013							      							  * 
* Autor: Cristian Soriano, Chenglong Zou					      			  *
* Descripció: Codi per llegir el fotorresistor	   					  		  *
******************************************************************************/

#include "fotoresistor.h"

/* Constructor de la classe */
FotoResistor::FotoResistor(uint8_t _pin)
{
	pin = _pin;
}




int FotoResistor::read()
{
	pinMode(pin, INPUT);
	
	/* Lectura de les dades */
	float counts = (float)analogRead(pin);
	if (counts < 0.0)
		counts = 0.0;
	else if (counts > 1023)
		counts = 1023;
	float Vout = Vref * counts / (ADCres_fotoresistor - 1);
	lux = (int)( ( Vref*luxRel*Vout - luxRel )  /  RL);
	
	return HUMITATEMPERATURA_OK;
}