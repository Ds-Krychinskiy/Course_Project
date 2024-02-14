#pragma once 
#include "../stdafx/stdafx.h"
#include "../Player/Player/Player.h"
#include "../Level_source/Levels/Levels.h"

class State;


class Game
{
    private: 
    std::stack<State*> m_States;
    sf::RenderWindow window;

    static constexpr unsigned int s_WindowSizeX = 1520;
	static constexpr unsigned int s_WindowSizeY = 720;
	inline static const std::string s_Name = "Course Project";
	static constexpr unsigned int s_MaxFPS = 60;


    Player *player;
    
    Levels* levels;
    sf::Texture world_background_tex;
    sf::Sprite world_background;
    sf::Image image_bg;

    public:

    Game();
    virtual ~Game();

    void run();
    void render(sf::RenderTarget &window);
    sf::RenderWindow *get_window(); 
    static const std::string get_name_of_window();
    
    void pushState(State* state);
	void popState();
	void changeState(State* state);
	State* peekState() const;
	void returnToMain();
};