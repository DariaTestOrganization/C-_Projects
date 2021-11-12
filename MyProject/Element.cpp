#include "Element.h"

Element::Element(Texture* texture, int pos)
{
    this->sprite.setTexture(*texture);
    this->sprite.setPosition(190.f + 50.f*static_cast<float>(pos), -this->sprite.getGlobalBounds().height);
    this->movementSpeed = 3.f;
}

Element::~Element()
{
}

Element::Element(const Element& el)
{
    sprite = el.sprite;
    movementSpeed = el.movementSpeed;
}

Element::Element(Element&& el) noexcept
{
    swap(sprite, el.sprite);
    swap(movementSpeed, el.movementSpeed);
}

Element& Element::operator=(const Element& el)
{
    if(this==&el)
        return *this;
    sprite = el.sprite;
    movementSpeed = el.movementSpeed;
    return *this;
}

Element& Element::operator=(Element&& el) noexcept
{
    if (this == &el)
        return *this;
    swap(sprite, el.sprite);
    swap(movementSpeed, el.movementSpeed);
    return *this;
}

FloatRect Element::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

const int Element::getMovementSpeed() const
{
    return movementSpeed;
}

void Element::setMovementSpeed(float mvSpeed)
{
    movementSpeed = mvSpeed;
}

void Element::effect(MyCar& car)
{
}

void Element::update()
{
    this->sprite.move(0.f, this->movementSpeed);
}

void Element::render(RenderTarget* target)
{
    target->draw(this->sprite);
}
