#include "Health_Bar.h"

Health_Bar::Health_Bar()
{
    this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
    this->playerHpBar.setFillColor(sf::Color::Red);
    this->playerHpBar.setPosition((sf::Vector2f(20.f, 20.f)));
    this->playerHpBarBack = this->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

Health_Bar::~Health_Bar()
{
}



void Health_Bar::update()
{
}

void Health_Bar::render(sf::RenderTarget &target)
{
}
