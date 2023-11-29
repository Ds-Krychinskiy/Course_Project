#pragma once 
#include "../stdafx/stdafx.h"
#include "../Player_source/Player/Player.h"
#include "../GUI_source/Game_interface/Game_interface.h"
#include "../Level_source/Levels/Levels.h"

class Game
{
    private: 

    bool pause;

    sf::Event event;

    Game_interface* game_interface;

    Player player;
    
    Levels* levels;

    public:

    Game();
    virtual ~Game();

    void stop_the_game();
    void update();
    void render(sf::RenderTarget &window);
};