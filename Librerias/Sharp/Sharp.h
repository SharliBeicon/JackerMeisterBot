#include <Arduino.h>

class Sharp{
	public:
		Sharp(int pin);

		float getDistance();
	private:
		int _pin;
		const float ResolutionADC=0.00488; 
		float _volt;
		
		float VoltToCM(){
			float invDistance = (_volt - 0.0129) / 12.82;
			return ((1/invDistance) - 0.42);
		}
};

Sharp::Sharp(int pin): _pin(pin){
	pinMode(_pin, INPUT);
}


float Sharp::getDistance(){
	_volt = ResolutionADC * analogRead(_pin);
	if(VoltToCM() < 0 or VoltToCM() > 120)
		return 999;
	else
		return VoltToCM();
}