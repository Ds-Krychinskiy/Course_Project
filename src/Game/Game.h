#pragma once 
#include "../stdafx/stdafx.h"
#include "../Player_source/Player/Player.h"
#include "../GUI_source/Game_interface/Game_interface.h"
#include "../State/State.h"
#include "../Menu/Menu.h"

class Game
{
    private: 
    std::stack<State*> m_States;


    sf::RenderWindow window;
    sf::VideoMode desktop;
    sf::Event event;

    sf::Texture world_background_tex;
    sf::Sprite world_background;
    sf::Image image_bg;

    Player *player;

    static constexpr unsigned int s_WindowSizeX = 1520;
	static constexpr unsigned int s_WindowSizeY = 720;
	inline static const sf::String s_Name = "Course Project";
	static constexpr unsigned int s_MaxFPS = 60;


    public:

    Game();
    virtual ~Game();
    sf::RenderWindow &get_window();
    static const sf::String get_name_of_window();
    void run();
    void updateCollision();
    void update();

    void pushState(State* state);
	void popState();
	void changeState(State* state);
	State* peekState() const;
	void returnToMain();
};