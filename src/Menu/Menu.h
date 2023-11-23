#include "../stdafx/stdafx.h"
#include "../Button/Button.h"

class Menu
{
private:
    std::vector<std::string> labelButton;
    sf::Texture textureButton;
public:
    Menu(std::string labelButton);
    ~Menu();
    void render(sf::RenderTarget& target);
    void initTexture();
};

