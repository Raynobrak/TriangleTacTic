#include "Game.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>

#include "board_constants.h"

sf::Vector2u WINDOW_SIZE = { 500u,500u };

Game::Game(PlayerType player1, PlayerType player2) {
	window_.create({ WINDOW_SIZE.x, WINDOW_SIZE.y }, "TriangleTacTic", sf::Style::Close);
	window_.setVerticalSyncEnabled(true);
	gameOver_ = false;

	p1_ = Player::createPlayerPtr(player1, coordinator_, window_);
	p2_ = Player::createPlayerPtr(player1, coordinator_, window_);
}

void Game::start() {
	while (!gameOver_) {
		p1_->playTurn();
		p2_->playTurn();
		render();
	}
}

void Game::render() {
	const auto& board = coordinator_.getReadonlyBoard();

	window_.clear();

	sf::Vector2f boardStart = BOARD_MARGIN * sf::Vector2f(static_cast<float>(WINDOW_SIZE.x), static_cast<float>(WINDOW_SIZE.y));
	float tileWidth = TILE_WIDTH * WINDOW_SIZE.x;
	float tileHeight = TILE_WIDTH * WINDOW_SIZE.y;

	for (pos_component_t line = 0; line < Board::UINT_BOARD_WIDTH; ++line) {
		for (pos_component_t col = 0; col < Board::UINT_BOARD_WIDTH; ++col) {
			sf::RectangleShape tile;
			tile.setPosition(boardStart + sf::Vector2f(col * tileWidth, line * tileHeight));
			tile.setSize({ tileWidth, tileHeight });
			tile.setOutlineThickness(3.f);
			tile.setOutlineColor(sf::Color::Cyan);

			auto symbolOnTile = coordinator_.getReadonlyBoard().getSymbolAt({ col,line });
			switch (symbolOnTile) {
			case Symbol::Crosses:
				tile.setFillColor(sf::Color::Red);
				break;
			case Symbol::Rounds:
				tile.setFillColor(sf::Color::Blue);
				break;
			case Symbol::Triangles:
				tile.setFillColor(sf::Color::Green);
				break;
			}

			window_.draw(tile);

		}
	}

	window_.display();
}
