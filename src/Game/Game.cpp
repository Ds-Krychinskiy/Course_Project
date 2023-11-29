#include "Game.h"


Game::Game() : pause{true}
{ 
    this->game_interface = new Game_interface();
    this->player = Player();
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

void Game::update()
{
}

void Game::render(sf::RenderTarget &window)
{
    this->player.render(window);
}
