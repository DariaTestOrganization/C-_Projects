#include "Car.h"

Car::Car(Texture* texture, int pos):Element(texture, pos)
{
}

Car::~Car()
{
}

void Car::effect(MyCar& car)
{
	car.decreaseHp(10);
}
