#include "stdafx.h"

#include "Buttom.h"

class Menu
{
private:
    vector<string> labelButton;
    sf::Texture textureButton;
public:
    Menu(string labelButton);
    ~Menu();
    void render(sf::RenderTarget& target);
    void inintTexture();
};

