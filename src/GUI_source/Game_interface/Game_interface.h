#pragma once

#include "../../stdafx/stdafx.h"
#include "../Health_Bar/Health_Bar.h"
#include "../Number_of_Coins/Number_of_Coins.h"

class Game_interface
{
private:
    Health_Bar* health_bar;
    Number_of_Coins* number_of_coins;

public:
    Game_interface();
    ~Game_interface();

    void update();
    void render(sf::RenderTarget &window);
};

