#pragma once
#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

#include <ctime>
#include <sstream>

class MyCar
{
private:

    Texture texture;
    Sprite sprite;

    int hp;
    int hpMax;

    int fuel;
    int fuelMax;

    unsigned coins;

    float movementSpeed;

public:
    MyCar();
    ~MyCar();
    MyCar(const MyCar& car);
    MyCar( MyCar&& car)noexcept;
    MyCar& operator=(const MyCar& car);
    MyCar& operator=(MyCar&& car)noexcept;

    const FloatRect getBounds()const;
    const int getHp()const;
    const int getHpMax()const;
    const int getFuel()const;
    const int getFuelMax()const;
    const int getCoins()const;
    const Texture& getTexture()const;
    const Sprite& getSprite()const;
    const float getMovementSpeed()const;

    void setHp(const int a);
    void setFuel(const int a);
    void setCoins(const int a);
    void setPosition(float x, float y);
    void setSavedParametrs(stringstream& ss);

    void addHp(const int a);
    void decreaseHp(const int a);

    void addFuel(const int a);
    void addCoins(const int a);

    void move(const float dirX, const float dirY);

    void update() ;
    void render(RenderTarget* target);
};

