#include "HumanPlayer.h"

#include <SFML/Window/Event.hpp>

#include "board_constants.h"

HumanPlayer::HumanPlayer(GameCoordinator& coordinator, sf::RenderWindow& window) : Player(coordinator), window_(window) {}

void HumanPlayer::playTurn() {
	sf::Event event;
	while (window_.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::MouseButtonReleased:
			switch (event.mouseButton.button) {
			case sf::Mouse::Left:
				tryToPlaceSymbolAt(getTilePosAt(currentMousePositionOnWindow()));
				break;
			case sf::Mouse::Right:
				tryToPlaceTriangleAt(getTilePosAt(currentMousePositionOnWindow()));
				break;
			}
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Space:
				tryToFinishTurn();
				break;
			}
			break;
		}
	}
}

sf::Vector2f HumanPlayer::currentMousePositionOnWindow() const {
	auto mousePos = sf::Mouse::getPosition(window_);
	return { static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };
}

TilePosition HumanPlayer::getTilePosAt(sf::Vector2f pointOnWindow) const
{
	auto windowSize = sf::Vector2f(window_.getSize());
	const sf::Vector2f normalizedPosRelativeToWindow = { pointOnWindow.x / windowSize.x, pointOnWindow.y / windowSize.y };

	if (normalizedPosRelativeToWindow.x > BOARD_MARGIN && normalizedPosRelativeToWindow.x < (1.f - BOARD_MARGIN) &&
		normalizedPosRelativeToWindow.y > BOARD_MARGIN && normalizedPosRelativeToWindow.y < (1.f - BOARD_MARGIN)) {

		const sf::Vector2f normalizedPosRelativeToGrid = (normalizedPosRelativeToWindow - sf::Vector2f(BOARD_MARGIN, BOARD_MARGIN)) / (1.f - 2.f * BOARD_MARGIN);
		float column = normalizedPosRelativeToGrid.x * static_cast<float>(Board::UINT_BOARD_WIDTH);
		float line = normalizedPosRelativeToGrid.y * static_cast<float>(Board::UINT_BOARD_WIDTH);

		return { static_cast<pos_component_t>(column), static_cast<pos_component_t>(line) };
	}
	else {
		return UNDEFINED_POS;
	}
}