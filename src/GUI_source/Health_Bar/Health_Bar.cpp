#include "Health_Bar.h"

Health_Bar::Health_Bar(float pos_x, float pos_y)
{
    this->hp_bar.setSize(sf::Vector2f(300.f, 25.f));
    this->hp_bar.setFillColor(sf::Color::Red);
    this->hp_bar.setPosition((sf::Vector2f(pos_x, pos_y)));
    this->hp_bar_back = this->hp_bar;
    this->hp_bar_back.setFillColor(sf::Color(25, 25, 25, 200));
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
