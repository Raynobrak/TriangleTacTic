#include "Player.h"

#include "HumanPlayer.h"
#include "AIPlayer.h"

#include <iostream>

std::unique_ptr<Player> Player::createPlayerPtr(PlayerType type, GameCoordinator& coordinator, sf::RenderWindow& window)
{
	switch (type)
	{
	case PlayerType::Human:
		return std::make_unique<HumanPlayer>(coordinator, window);
		break;
	case PlayerType::AI:
		return std::make_unique<AIPlayer>(coordinator);
		break;
	default:
		throw std::invalid_argument("Player type is invalid.");
	}
}

Player::Player(GameCoordinator& coordinator) : coordinator_(coordinator) {}

void Player::tryToFinishTurn() {
	if (!coordinator_.finishTurn()) {
		logMessage("The turn cannot be finished right now.");
	}
}

void Player::tryToPlaceSymbolAt(TilePosition pos) {
	auto validity = coordinator_.placeSymbolAt(pos);
	switch (validity)
	{
	case MoveValidity::Valid:
		// everything ok
		break;
	case MoveValidity::SymbolAlreadyPlaced:
		logMessage("The symbol has already been placed for this turn.");
		break;
	case MoveValidity::OverlappingOrOutOfBounds:
		logMessage("You cannot place a symbol here.");
		break;
	}
}

void Player::tryToPlaceTriangleAt(TilePosition pos) {
	auto validity = coordinator_.placeTriangleAt(pos);
	switch (validity)
	{
	case MoveValidity::Valid:
		// everything ok
		break;
	case MoveValidity::TriangleAlreadyPlaced:
		logMessage("The triangle has already been placed for this turn.");
		break;
	case MoveValidity::OverlappingOrOutOfBounds:
		logMessage("You cannot place a triangle here.");
		break;
	}
}

void Player::logMessage(std::string msg) {
	// TODO : logger le message dans un meilleur endroit que la console...
	std::cout << msg << std::endl;
}
