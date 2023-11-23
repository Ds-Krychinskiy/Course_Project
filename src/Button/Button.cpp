#include "./Button.h"
#include "Button.h"

Button::Button(sf::String label_button, sf::Color bg_color, sf::Color text_color, sf::Vector2f button_size, int char_size)
{   this->font = sf::Font();
    this->font.loadFromFile("../../fonts/font.ttf");
    if(!this->font.loadFromFile("../../fonts/font.ttf"))
    {
        std::cout << "in Button construction" << std::endl;
    }
    this->label = sf::Text(label_button, font, char_size);
    this->button.setSize(button_size);
    this->button.setFillColor(bg_color);
}

Button::~Button()

{
}


// void Button::set_font(sf::Font &font)
// {
//     this->label.setFont(font);
// }

void Button::set_back_color(sf::Color color)
{
    button.setFillColor(color);
}

// void Button::set_text_color(sf::Color color)
// {
//     this->label.setColor(color);
// }

// void Button::set_position(sf::Vector2f pos)
// {
//     this->button.setPosition(pos);

//     float x_pos = (pos.x + button.getGlobalBounds().width / 2) -(label.getGlobalBounds().width / 2);
//     float y_pos = (pos.y + button.getGlobalBounds().height / 2) -(label.getGlobalBounds().height / 2);
//     label.setPosition({x_pos, y_pos});
// }

// void Button::drawTo(sf::RenderWindow &window)
// {
//     window.draw(button);
//     window.draw(label);
// }

bool Button::is_mouse_over(sf::RenderWindow &window)
{
    float mouse_x = sf::Mouse::getPosition(window).x;
    float mouse_y = sf::Mouse::getPosition(window).y;

    float btn_pos_x = button.getPosition().x;
    float btn_pos_y = button.getPosition().y;
    float btn_x_pos_width = button.getPosition().x + button.getLocalBounds().width;
    float btn_y_pos_height = button.getPosition().y + button.getLocalBounds().height;
    if(mouse_x < btn_x_pos_width && mouse_x > btn_pos_x && mouse_y < btn_y_pos_height && mouse_y >btn_pos_y)
    {
        return true;
    }
    return false;
}
