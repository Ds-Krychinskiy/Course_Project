#include "Game.h"


Game::Game() : pause{true}
{ 
    this->game_interface = Game_interface();
    this->player = new Player();
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
