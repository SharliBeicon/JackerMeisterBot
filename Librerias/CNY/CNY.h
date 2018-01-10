#include <Arduino.h>

class CNY{
	public:
		CNY(int pin);
		bool onBlack();
	private:
		int _pin;
		const float ResolutionADC=0.00488;
};

CNY::CNY(int pin): _pin(pin){
	pinMode(_pin, INPUT);
}

bool CNY::onBlack(){
	return ((analogRead(_pin) * ResolutionADC) > 4);
}

