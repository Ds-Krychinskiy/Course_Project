#include "Game_interface.h"

Game_interface::Game_interface()
{
    this->health_bar = new Health_Bar(200.f, 200.f);
    this->number_of_coins = new Number_of_Coins();
}

Game_interface::~Game_interface()
{
    delete this->health_bar;
    delete this->number_of_coins;
}

void Game_interface::render(sf::RenderTarget &window)
{
}

void Game_interface::update()
{
}
