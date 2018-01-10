#include <Arduino.h>

class Motor {
	public:
		Motor(int pin1, int pin2, int speed);

		void moveForward();
		void moveBackward();
		void stop();
		void changeSpeed(int newSpeed);
	private:
		int _pin1;
		int _pin2;
		int _speed;
};

Motor::Motor(int pin1, int pin2, int speed): _pin1(pin1), _pin2(pin2), _speed(speed){
	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
}

void Motor::moveForward(){
	analogWrite(_pin1, _speed);
	analogWrite(_pin2, 0);
}

void Motor::moveBackward(){
	analogWrite(_pin1, 0);
	analogWrite(_pin2, _speed);
}

void Motor::stop(){
	analogWrite(_pin1, 0);
	analogWrite(_pin2, 0);
}

void Motor::changeSpeed(int newSpeed){
	_speed = newSpeed;
}