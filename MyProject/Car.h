#pragma once
#include "Element.h"
class Car :
    public Element
{

public:
    Car(Texture* texture, int pos);
    ~Car() override;

    void effect(MyCar& car) override;
};

