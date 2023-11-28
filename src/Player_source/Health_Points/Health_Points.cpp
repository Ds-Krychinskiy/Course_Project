#include "Health_Points.h"

Health_Points::Health_Points()
{
    
    this->hpMax = 100;
    this->hp = this->hpMax;

    this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
    this->playerHpBar.setFillColor(sf::Color::Red);
    this->playerHpBar.setPosition((sf::Vector2f(20.f, 20.f)));
    this->playerHpBarBack = this->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

Health_Points::~Health_Points()
{
}

const int &Health_Points::getHp() const
{   
    return this->hp;
}

const int &Health_Points::getHpMax() const
{
    return this->hpMax;
}


void Health_Points::setHp(const int hp)
{
}

void Health_Points::loseHp(const int value)
{
}


void Health_Points::update()
{
}

void Health_Points::render(sf::RenderTarget &target)
{
}
