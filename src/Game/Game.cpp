#include "Game.h"


Game::Game() : pause{true}
{ 

}

Game::~Game()
{
}



void Game::stop_the_game()
{
    if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
    {
        this->pause = true;
    }
}
