#include "MyCar.h"

MyCar::MyCar()
{
	this->texture.loadFromFile("Texture/mycar.png");
	this->sprite.setTexture(this->texture);

	movementSpeed = 5.f;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->coins = 0;
	this->fuelMax = 5000;
	this->fuel = this->fuelMax;
	
}

MyCar::~MyCar()
{
}

MyCar::MyCar(const MyCar& car)
{
	texture = car.texture;
	sprite = car.sprite;
	hp = car.hp;
	hpMax= car.hpMax;
	fuel=car.fuel;
	fuelMax = car.fuelMax;
	coins = car.coins;
	movementSpeed = car.movementSpeed;
}

MyCar::MyCar(MyCar&& car) noexcept
{
	swap(texture, car.texture);
	swap(sprite, car.sprite);
	swap(hp, car.hp);
	swap(hpMax, car.hpMax);
	swap(fuel, car.fuel);
	swap(fuelMax, car.fuelMax);
	swap(coins, car.coins);
	swap(movementSpeed, car.movementSpeed);
}

MyCar& MyCar::operator=(const MyCar& car)
{
	if(this == &car)
		return *this;
	texture = car.texture;
	sprite = car.sprite;
	hp = car.hp;
	hpMax = car.hpMax;
	fuel = car.fuel;
	fuelMax = car.fuelMax;
	coins = car.coins;
	movementSpeed = car.movementSpeed;
	return *this;
}

MyCar& MyCar::operator=(MyCar&& car) noexcept
{
	if (this == &car)
		return *this;
	swap(texture, car.texture);
	swap(sprite, car.sprite);
	swap(hp, car.hp);
	swap(hpMax, car.hpMax);
	swap(fuel, car.fuel);
	swap(fuelMax, car.fuelMax);
	swap(coins, car.coins);
	swap(movementSpeed, car.movementSpeed);
	return *this;
}

const FloatRect MyCar::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int MyCar::getHp() const
{
	return hp;
}

const int MyCar::getHpMax() const
{
	return hpMax;
}

const int MyCar::getFuel() const
{
	return fuel;
}

const int MyCar::getFuelMax() const
{
	return fuelMax;
}

const int MyCar::getCoins() const
{
	return coins;
}

const Texture& MyCar::getTexture() const
{
	return texture;
}

const Sprite& MyCar::getSprite() const
{
	return sprite;
}

const float MyCar::getMovementSpeed() const
{
	return movementSpeed;
}

void MyCar::setHp(const int a)
{
	hp = a;
}

void MyCar::setFuel(const int a)
{
	fuel = a;
}

void MyCar::setCoins(const int a)
{
	coins = a;
}

void MyCar::setPosition(float x, float y)
{
	this->sprite.setPosition(x,y);
}

void MyCar::setSavedParametrs(stringstream& ss)
{
	ss >> hp;
	ss >> fuel;
	ss >> coins;

}

void MyCar::addHp(const int a)
{
	hp += a;
}

void MyCar::decreaseHp(const int a)
{
	hp -= a;
}

void MyCar::addFuel(const int a)
{
	fuel += a;
}

void MyCar::addCoins(const int a)
{
	coins += a;
}

void MyCar::move(const float dirX, const float dirY)
{
	this->sprite.move(dirX*movementSpeed, dirY* movementSpeed);
}

void MyCar::update()
{
	if (hp > hpMax)
		hp = hpMax;
	if (hp <0)
		hp = 0;

	if (fuel > fuelMax)
		fuel = fuelMax;
	if (fuel < 0)
		fuel = 0;

	fuel -= 0.00001;
}

void MyCar::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
