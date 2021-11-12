#pragma once
#include "Element.h"
class Fuel :
    public Element
{

public:
    Fuel(Texture* texture, int pos);
    ~Fuel() override;

    void effect(MyCar& car) override;
};

