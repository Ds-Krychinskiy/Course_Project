#pragma once
#include "../stdafx/stdafx.h"
#include "../GUI_source/Primary_Menu/Primary_Menu.h"
#include "../Player_source/Player/Player.h"


class Windows
{
private:
    sf::RenderWindow window;
    sf::VideoMode desktop;
    sf::Event event;

    sf::Texture world_background_tex;
    sf::Sprite world_background;
    sf::Image image_bg;


    Primary_Menu* primary_menu;
    std::vector<sf::String> label_menu;
public:
    Windows();
    virtual ~Windows();
    const sf::RenderWindow &getWindows() const;
    void update();
    void render();
};

