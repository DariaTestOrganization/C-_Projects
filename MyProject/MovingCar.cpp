#include "MovingCar.h"

MovingCar::MovingCar(Texture* texture, int pos):Element(texture, pos)
{
	isLeft = true;
	carTimerMax = this->movementSpeed*50.f;
	carTimer = 0;
}

MovingCar::~MovingCar()
{
}

void MovingCar::update()
{
	this->sprite.move(0.f, this->movementSpeed);

	carTimer += 0.5f*this->movementSpeed;

	if (carTimer >= carTimerMax) {
		if (isLeft) {
			this->sprite.move(50.f, 0.f);
			isLeft = false;
		}
		else {
			this->sprite.move(-50.f, 0.f);
			isLeft = true;
		}
		carTimer = 0.f;
	}	
}

void MovingCar::effect(MyCar& car)
{
	car.decreaseHp(10);
}
