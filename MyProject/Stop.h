#pragma once
#include "Element.h"
class Stop :
    public Element
{
public:
    Stop(Texture* texture, int pos);
    ~Stop() override;

    void effect(MyCar& car) override;
};

