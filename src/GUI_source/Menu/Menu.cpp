#include "./Menu.h"

Menu::Menu(Game* game) : State(game)
{
	m_TitleLabel.getText().setString(Game::get_name_of_window());
	// m_TitleLabel.getText().setFont(ResourceManager::getInstance().getFont(res::Font::Pixel));
	m_TitleLabel.getText().setCharacterSize(50);
	m_TitleLabel.getText().setPosition(m_Game->get_window().getSize().x - m_TitleLabel.getText().getGlobalBounds().width - 20, 20);

	// m_BackgroundTexture = ResourceManager::getInstance().getTexture(res::Texture::MenuBackgroundForest);
	m_Background.setTexture(m_BackgroundTexture);

	m_StartButton.setText("new game");
	m_StartButton.setFont(res::Font::Roboto);
	m_StartButton.setAlignment(Button::Alignment::Center);
	m_StartButton.setPosition(sf::Vector2f(30, 100));
	m_StartButton.setSize(sf::Vector2f(200, 30));
	m_StartButton.setAction([&]() {
		std::cerr << "Switch to GameState: Starting the game" << std::endl;
		m_Game->pushState(new GameState(m_Game));
	});

	m_ExitButton.setText("exitame");
	m_ExitButton.setFont(res::Font::Roboto);
	m_ExitButton.setAlignment(Button::Alignment::Center);
	m_ExitButton.setPosition(sf::Vector2f(30, 200));
	m_ExitButton.setSize(sf::Vector2f(200, 30));
	m_ExitButton.setAction([&]() {
		std::cerr << "Exit button clicked" << std::endl;
		m_Game->get_window().close();
	});


}

void Menu::update(sf::Time deltaTime)
{
	// m_MusicPlayer.play();
	m_Game->get_window().setView(m_Game->get_window().getDefaultView());
}

void Menu::render()
{
	m_Game->get_window().clear();
	m_Game->get_window().draw(m_Background);
	m_Game->get_window().draw(m_StartButton);
	m_Game->get_window().draw(m_ExitButton);
	m_Game->get_window().draw(m_TitleLabel);
	m_Game->get_window().display();
}

void Menu::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::Closed)
	{
		m_Game->get_window().close();
	}
	m_StartButton.handleEvent(event);
	m_ExitButton.handleEvent(event);
}