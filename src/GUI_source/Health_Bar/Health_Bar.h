#pragma once

#include "../../stdafx/stdafx.h"


class Health_Bar
{
private:
    
    sf::RectangleShape hp_bar;
    sf::RectangleShape hp_bar_back;

public:
    Health_Bar(float pos_x, float pos_y);
    ~Health_Bar();

    
    //Functions
    void update();
    void render(sf::RenderTarget& target);
};


