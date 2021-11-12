#include "Stop.h"

Stop::Stop(Texture* texture, int pos):Element(texture, pos)
{
}

Stop::~Stop()
{
}

void Stop::effect(MyCar& car)
{
	car.decreaseHp(1);
}
