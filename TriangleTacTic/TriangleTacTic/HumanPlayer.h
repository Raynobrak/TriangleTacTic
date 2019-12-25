#pragma once

#include "Player.h"
#include "GameCoordinator.h"

#include <SFML/Graphics/RenderWindow.hpp>

class HumanPlayer : public Player {
public:
	HumanPlayer(GameCoordinator& coordinator, sf::RenderWindow& window);
	void playTurn() override;
private:
	TilePosition getTilePosAt(sf::Vector2f pointOnWindow) const;
	sf::Vector2f currentMousePositionOnWindow() const;

	sf::RenderWindow& window_;
};

