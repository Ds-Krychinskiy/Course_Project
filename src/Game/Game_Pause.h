#include "../Button/Button.h"
#include "../State/State.h"


class Game_Pause : public State
{
private:
    sf::Texture m_BackgroundTexture;
	sf::Sprite m_Background;

	Button m_ContinueButton;
	Button m_MainMenuButton;


	sf::Text m_TitleLabel;
public:
    Game_Pause(Game* game);
    ~Game_Pause();

	// Inherited via State
	virtual void render() override;
	virtual void update(sf::Time deltaTime) override;
	virtual void handleEvent(const sf::Event& event) override;
};

