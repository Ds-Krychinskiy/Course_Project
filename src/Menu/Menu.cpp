#include "Menu.h"

Menu::Menu(string labelButton)
{
    
}

Menu::~Menu()
{
}


void Menu::inintTexture()
{   
    //Load a texture from file
    if(!this->textureButton.loadFromFile("./texture/ship.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file." << "\n";
    }
}

void Menu::render(sf::RenderTarget &target)
{
    // target.draw(this->sprite);
}
