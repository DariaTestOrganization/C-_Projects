#include "Coin.h"

Coin::Coin(Texture* texture, int pos):Element(texture, pos)
{
}

Coin::~Coin()
{
}

void Coin::effect(MyCar& car)
{
	car.addCoins(2);
}
