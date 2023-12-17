#include "../stdafx/stdafx.h"

class Button : public sf::Drawable
{
private:
	sf::Text m_Text;
    sf::RectangleShape m_InnerButton;
	sf::RectangleShape m_OuterButton;
public:
    Button();
    ~Button();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;
	void handleEvent(const sf::Event& event);

    void setAction(std::function<void()> actionTodo);
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	// void setAlignment(Alignment alignment);
	void setText(std::string text);
	// void setFont(res::Font font);
	void setInnerColor(sf::Color color);
	void setOutlineColor(sf::Color color);
	void setTextColor(sf::Color color);

	sf::FloatRect getGlobalBounds() const { return m_OuterButton.getGlobalBounds(); }
};

