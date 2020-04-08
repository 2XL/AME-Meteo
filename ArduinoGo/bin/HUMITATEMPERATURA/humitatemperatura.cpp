/******************************************************************************
* Nom del fitxer: humitatemperatura.cpp						     			  *
* Data: 11/XI/2013							      							  * 
* Autor: David Gamez Alari (david.gameza@urv.cat)			      			  *
* Descripció: llibreria per a la realització de la pràctica de l'assignatura  *
*	Aplicacions Mòbils i Encastades, corresponent al component DHT11	  	  *
*	(sensor d'Humitat i temperatura)									  	  *
* Universitat Rovira i Virgili						      					  *
* Departament d'Enginyeria Informàtica i Matemàtiques			      		  *
******************************************************************************/
#include "humitatemperatura.h"

/* Constructor de la classe */

Humitatemperatura::Humitatemperatura(uint8_t _pin)
{
	pin = _pin;
}


/******************************************************************************
* Funció: read			 													  *
* Descripció: funció que fa una crida al sensor DHT11 per a obtenir una dada  *
*	d'humitat i temperatura													  *
* Paràmetres d'entrada: void												  *
* Paràmetres de sortida : int -> codi d'error								  *
*******************************************************************************/	


int Humitatemperatura::read()
{
	/* Buffer per a rebre dades */
	uint8_t bits[5];
	uint8_t cnt = 7;
	uint8_t idx = 0;

	/* Buidem el buffer */
	for (int i=0; i< 5; i++) bits[i] = 0;

	/* Fem una petició de dades */
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	delay(18);
	digitalWrite(pin, HIGH);
	delayMicroseconds(40);
	pinMode(pin, INPUT);

	/* Tractament d'errors */	
	
	/* ACKNOWLEDGE or TIMEOUT */
	unsigned int loopCnt = 10000;
	while(digitalRead(pin) == LOW)
		if (loopCnt-- == 0) return HUMITATEMPERATURA_ERROR_TIMEOUT;

	loopCnt = 10000;
	while(digitalRead(pin) == HIGH)
		if (loopCnt-- == 0) return HUMITATEMPERATURA_ERROR_TIMEOUT;

	/* Lectura de les dades */
	/* READ OUTPUT - 40 BITS => 5 BYTES or TIMEOUT */
	for (int i=0; i<40; i++)
	{
		loopCnt = 10000;
		while(digitalRead(pin) == LOW)
			if (loopCnt-- == 0) return HUMITATEMPERATURA_ERROR_TIMEOUT;

		unsigned long t = micros();

		loopCnt = 10000;
		while(digitalRead(pin) == HIGH)
			if (loopCnt-- == 0) return HUMITATEMPERATURA_ERROR_TIMEOUT;

		if ((micros() - t) > 40) bits[idx] |= (1 << cnt);
		if (cnt == 0)   // next byte?
		{
			cnt = 7;    // restart at MSB
			idx++;      // next byte!
		}
		else cnt--;
	}

	/* Ho escrivim a les variables correctes dintre de la classe */
	humidity    = bits[0]; 
	temperature = bits[2]; 

	uint8_t sum = bits[0] + bits[2];  

	/* Error de checksum ?, dades corruptes ?*/
	if (bits[4] != sum) return HUMITATEMPERATURA_ERROR_CHECKSUM;

	return HUMITATEMPERATURA_OK;
}

