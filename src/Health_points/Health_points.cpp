#include "Health_points.h"

Health_points::Health_points()
{
}

Health_points::~Health_points()
{
}

const int &Health_points::getHp() const
{   
    return this->hp;
}

const int &Health_points::getHpMax() const
{
    return this->hpMax;
}

void Health_points::move(const float dirX, const float dirY)
{
}

void Health_points::update()
{
}

void Health_points::render(sf::RenderTarget &target)
{
}
