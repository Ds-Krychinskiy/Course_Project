#pragma once
#include "../../stdafx/stdafx.h"
#include "../Bonus/Bonus.h"
#include "../Platforms/Platforms.h"
#include "../Enemy/Enemy.h"


class Levels
{
private:
    std::string label;
    std::vector<Bonus*> bones;

    std::vector<Enemy*> enemy;

    Platforms* platform;
public:
    Levels(std::string label);
    ~Levels();

    void update();
    void render(sf::RenderTarget &window);
};


