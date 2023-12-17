#include "./Game.h"
#include "Game.h"


Game::Game() : window({Game::s_WindowSizeX, Game::s_WindowSizeY}, Game::s_Name)
{ 
    this->image_bg.loadFromFile("../texture/libra.jpg");
    if(!this->world_background_tex.loadFromImage(this->image_bg))
    {
        std::cout << "File upload failed" << std::endl;
    } 
    this->world_background.setTexture(this->world_background_tex);
    // this->game_interface = new Game_interface();
    this->pushState(new Menu(this)); 
    this->player = new Player();
}

Game::~Game()
{
}

sf::RenderWindow &Game::get_window() 
{
    return this->window;
}



const sf::String Game::get_name_of_window()
{
    return s_Name;
}



void Game::run()
{   
    while(this->window.isOpen())
    {
        this->update();
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Escape) { window.close(); }
                // if (event.key.code == sf::Keyboard::Up) {  primary_menu->MoveUp(); }       
                // if (event.key.code == sf::Keyboard::Down) {  primary_menu->MoveDown(); } 
                // if (event.key.code == sf::Keyboard::Return)                                    
                // {

                //     switch (primary_menu->getSelectedMenuNumber())
                //     {
                //     case 0:game_start();  break;
                //     case 1:options();     break;
                //     case 2:about_game();  break;
                //     case 3:main_window.close(); break;
                //     default:break;
                //     }
                // }
            }
        } 
        this->window.clear();
        this->window.draw(this->world_background);
        this->player->render(this->window);

        this->window.display();  
    }
}

void Game::updateCollision()
{
    //Left world collision
    if(this->player->getBounds().left < 0.f)
    {
        this->player->setPosition(0.f, this->player->getBounds().top);
    }

    //Right world collision
    else if(this->player->getBounds().left + this->player->getBounds().width >= this->window.getSize().x)
    {
        this->player->setPosition(this->window.getSize().x - this->player->getBounds().width, this->player->getBounds().top);
    }
    //Top world collision
    if(this->player->getBounds().top < 0.f)
    {
        this->player->setPosition(this->player->getBounds().left, 0.f);
    }
    //Bottom world collision
    else if(this->player->getBounds().top + this->player->getBounds().height >= this->window.getSize().y)
    {
        this->player->setPosition(this->player->getBounds().left, this->window.getSize().y -  this->player->getBounds().height);
    }
}

void Game::update()
{
    this->updateCollision();
}
