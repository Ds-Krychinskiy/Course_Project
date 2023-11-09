#include "./Window.h"

Windows::Windows()
{
    this->desktop = sf::VideoMode::getDesktopMode();
    this->window.create(sf::VideoMode({1024, 768}, desktop.bitsPerPixel), "Course Project", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(60);
}
Windows::~Windows()
{
    
}

const sf::RenderWindow &Windows::getWindows() const
{
    return this->window;
}

void Windows::update()
{
    while(this->window.pollEvent(this->event))
    {
        if(this->event.type == sf::Event::Closed)
        {
            this->window.close();
        }
    //     if (event.type == sf::Event::Resized)
    //     {
    //         sf::FloatRect visibleArea({0, 0}, {static_cast<float>(event.size.width), static_cast<float>(event.size.height)});
    //         this->window.setView(sf::View(visibleArea));
    //     }
    // }
}


void Windows::render()
{
    this->window.clear();
}
