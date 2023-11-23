#pragma once 
#include "../stdafx/stdafx.h"

class Game
{
    private: 
    sf::Event event;
    bool pause;
    

    
    public:
    Game();
    virtual ~Game();
    void stop_the_game();
};