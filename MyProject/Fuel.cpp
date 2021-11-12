#include "Fuel.h"

Fuel::Fuel(Texture* texture, int pos):Element(texture, pos)
{
}

Fuel::~Fuel()
{
}

void Fuel::effect(MyCar& car)
{
	car.addFuel(500);
}
