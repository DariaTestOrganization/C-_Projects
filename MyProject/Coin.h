#pragma once
#include "Element.h"
class Coin :
    public Element
{
public:
    Coin(Texture* texture, int pos);
    ~Coin() override;

    void effect(MyCar& car) override;


};

