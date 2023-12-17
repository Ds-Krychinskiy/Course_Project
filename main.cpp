#include "./src/Game/Game.h"
#include "./src/Player_source/Player/Player.h"




int main() 
{   
    srand(time(static_cast<unsigned>(0)));
    Game game;
    game.run();
    return 0;
}


