#pragma once

#include "../stdafx/stdafx.h"
#include "./Game.h"
#include "../State/State.h"

class GameState : public State
{
private:
    float m_FrameTime;

public:
    GameState(Game* game);
    ~GameState();
    virtual void render() override;
	virtual void update(sf::Time deltaTime) override;
    void updateCollision();

	virtual void handleEvent(const sf::Event& event) override;
};


