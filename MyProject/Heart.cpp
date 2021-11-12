#include "Heart.h"

Heart::Heart(Texture* texture, int pos):Element(texture, pos)
{
}

Heart::~Heart()
{
}

void Heart::effect(MyCar& car)
{
	car.addHp(5);
}
