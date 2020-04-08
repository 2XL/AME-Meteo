package FotoResistor;



#define FOTORESISTOR_LIB_VERSION 0.1
#define HUMITATEMPERATURA_OK				 0
#define HUMITATEMPERATURA_ERROR_TIMEOUT		-1

const float ADCres_fotoresistor = 1023.0;
const float luxRel = 500.0;
const float RL = 10.0;
const float Vref = 5.0;



public class FotoResistor {
 


	class FotoResistor
	{
		public:
			uint8_t pin;
			FotoResistor(uint8_t _pin);
	    	int read();
			int lux;
	};


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
}
