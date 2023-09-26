#include "stdafx.h"

class Windows
{
private:
    sf::RenderWindow window;

public:
    Windows();
    ~Windows();
    void updatePlayer();
    void update();
    void renderPlayer();
    void render();
};

