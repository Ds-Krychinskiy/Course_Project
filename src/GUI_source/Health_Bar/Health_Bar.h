#include "../../stdafx/stdafx.h"


class Health_Bar
{
private:
    
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

public:
    Health_Bar();
    ~Health_Bar();

    
    //Functions

    void update();
    void render(sf::RenderTarget& target);
};


