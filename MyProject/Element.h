#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "MyCar.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class Element
{
protected:
	Sprite sprite;

	float movementSpeed;

public:
	Element(Texture* texture, int pos);
	virtual ~Element()=0;
	Element(const Element& el);
	Element(Element&& el) noexcept;
	Element& operator=(const Element& el);
	Element & operator=(Element&& el) noexcept;

	FloatRect getBounds()const;
	const int getMovementSpeed()const;

	void setMovementSpeed(float mvSpeed);

	virtual void effect(MyCar& car);

	virtual void update();
	void render(RenderTarget* target);
};

