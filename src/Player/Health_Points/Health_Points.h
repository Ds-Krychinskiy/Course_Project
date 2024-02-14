#pragma once
#include "../../stdafx/stdafx.h"


class Health_Points
{
private:
    int hp;
    int hpMax;

    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

public:
    Health_Points();
    ~Health_Points();
    const int &getHp() const;
    const int &getHpMax() const;


    void setHp(const int hp);
    void loseHp(const int value);
    
    //Functions

    void update();
    void render(sf::RenderTarget& target);
};


