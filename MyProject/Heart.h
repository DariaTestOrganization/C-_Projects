#pragma once
#include "Element.h"
class Heart :
    public Element
{

public:
    Heart(Texture* texture, int pos);
    ~Heart() override;

    void effect(MyCar& car) override;
};

