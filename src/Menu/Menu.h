#include "../stdafx/stdafx.h"
#include "../Buttom/Buttom.h"

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

