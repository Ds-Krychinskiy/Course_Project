#pragma once 
#include "../stdafx/stdafx.h"

class Button
{
private:
    sf::RectangleShape button;
    sf::Font font;
    sf::Text label;
public:

    Button(sf::String label_button, sf::Color bg_color, sf::Color text_color, sf::Vector2f button_size, int char_size);
    ~Button();
    // void set_font(sf::Font &font);
    void set_back_color(sf::Color color);
    // void set_text_color(sf::Color color);
    // void set_position(sf::Vector2f pos);
    // void drawTo(sf::RenderWindow& window);
    bool is_mouse_over(sf::RenderWindow& window);
};


