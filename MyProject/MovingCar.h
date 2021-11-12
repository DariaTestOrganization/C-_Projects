#pragma once
#include "Element.h"
class MovingCar :
    public Element
{
private:
    bool isLeft;

    float carTimer;
    float carTimerMax;

public:
    MovingCar(Texture* texture, int pos);
    ~MovingCar() override;

    void update() override;
    void effect(MyCar& car) override;
};

