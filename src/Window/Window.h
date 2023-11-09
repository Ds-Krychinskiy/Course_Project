#pragma once
#include "../stdafx/stdafx.h"


class Windows
{
private:
    sf::RenderWindow window;
    sf::VideoMode desktop;
    sf::Event event;

public:
    Windows();
    virtual ~Windows();
    const sf::RenderWindow &getWindows() const;
    void update();
    void render();
};

