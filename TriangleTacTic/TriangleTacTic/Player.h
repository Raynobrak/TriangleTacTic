#pragma once

#include "TilePosition.h"
#include "GameCoordinator.h"
#include "PlayerType.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <memory>

class Player {
public:
	static std::unique_ptr<Player> createPlayerPtr(PlayerType type, GameCoordinator& coordinator, sf::RenderWindow& window);

	Player(GameCoordinator& coordinator);

	virtual void playTurn() = 0;
protected:
	GameCoordinator& coordinator_;

	void tryToFinishTurn();
	void tryToPlaceSymbolAt(TilePosition pos);
	void tryToPlaceTriangleAt(TilePosition pos);

	void logMessage(std::string msg);
};
