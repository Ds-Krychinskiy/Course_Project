#include "./Menu.h"
#include "../../Game/GameState.h"

Menu::Menu(Game* game) : State(game)
{	
	// this->m_StartButton = Button();
	// this->m_ExitButton = Button();
	this->m_TitleLabel.getText().setString(Game::get_name_of_window());
	// m_TitleLabel.getText().setFont(ResourceManager::getInstance().getFont(res::Font::Pixel));
	this->m_TitleLabel.getText().setCharacterSize(50);
	this->m_TitleLabel.getText().setPosition(this->m_Game->get_window()->getSize().x - this->m_TitleLabel.getText().getGlobalBounds().width - 20, 20);

	// m_BackgroundTexture = ResourceManager::getInstance().getTexture(res::Texture::MenuBackgroundForest);
	this->m_Background.setTexture(m_BackgroundTexture);

	this->m_StartButton.setText("new game");
	// this->m_StartButton.setFont(res::Font::Roboto);
	this->m_StartButton.setAlignment(Button::Alignment::Center);
	this->m_StartButton.setPosition(sf::Vector2f(30, 100));
	this->m_StartButton.setSize(sf::Vector2f(200, 30));
	this->m_StartButton.setAction([&]() {
		std::cerr << "Switch to GameState: Starting the game" << std::endl;
		this->m_Game->pushState(new GameState(m_Game));
	});

	this->m_ExitButton.setText("exitame");
	// this->m_ExitButton.setFont(res::Font::Roboto);
	this->m_ExitButton.setAlignment(Button::Alignment::Center);
	this->m_ExitButton.setPosition(sf::Vector2f(30, 200));
	this->m_ExitButton.setSize(sf::Vector2f(200, 30));
	this->m_ExitButton.setAction([&]() {
		std::cerr << "Exit button clicked" << std::endl;
		this->m_Game->get_window()->close();
	});
	std::cout << "Menu::Menu was work" << std::endl;
}

void Menu::update(sf::Time deltaTime)
{
	// m_MusicPlayer.play();
	this->m_Game->get_window()->setView(this->m_Game->get_window()->getDefaultView());
}

void Menu::render()
{
	this->m_Game->get_window()->clear();
	this->m_Game->get_window()->draw(m_Background);
	this->m_Game->get_window()->draw(m_StartButton);
	this->m_Game->get_window()->draw(m_ExitButton);
	this->m_Game->get_window()->draw(m_TitleLabel);
	this->m_Game->get_window()->display();
}

void Menu::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::Closed)
	{
		this->m_Game->get_window()->close();
	}
	this->m_StartButton.handleEvent(event);
	this->m_ExitButton.handleEvent(event);
}