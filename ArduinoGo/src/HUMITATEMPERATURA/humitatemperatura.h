/******************************************************************************
* Nom del fitxer: humitatemperatura.h					     			      *
* Data: 11/XI/2013							      							  * 
* Autor: David Gamez Alari (david.gameza@urv.cat)			      			  *
* Descripció: llibreria per a la realització de la pràctica de l'assignatura  *
*	Aplicacions Mòbils i Encastades, corresponent al component DHT11	  	  *
*	(sensor d'Humitat i temperatura)									  	  *
* Universitat Rovira i Virgili						      					  *
* Departament d'Enginyeria Informàtica i Matemàtiques			      		  *
******************************************************************************/
#include "Arduino.h"

#define HUMITATEMPERATURA_LIB_VERSION 0.1
#define HUMITATEMPERATURA_OK				 0
#define HUMITATEMPERATURA_ERROR_CHECKSUM	-1
#define HUMITATEMPERATURA_ERROR_TIMEOUT		-2

class Humitatemperatura
{
	public:
		uint8_t pin;
		Humitatemperatura(uint8_t _pin);
    	int read();
		int humidity;
		int	temperature;
};


