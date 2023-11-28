#include "Number_of_Coins.h"
Number_of_Coins::Number_of_Coins() 
{   
    this->number_of_coins = 0;
    this->load_font_from_file();
}


Number_of_Coins::~Number_of_Coins()
{
}

void Number_of_Coins::load_font_from_file()
{
    this->font = sf::Font();
    if(!this->font.loadFromFile("../../../fonts/font.ttf"))
    {
        std::cout << "in Number_of_Coins construction" << std::endl;
    }
    // this->label = sf::Text(label_button, font, char_size);
    // this->button.setSize(button_size);
    // this->button.setFillColor(bg_color);
}