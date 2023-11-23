#include "../stdafx/stdafx.h"

class Player
{
private:
    sf::Sprite sprite_player;
    sf::Texture texture_player; 
    sf::Image image_player;
public:
    Player();
    ~Player();
    void render(sf::RenderTarget &target);


};

