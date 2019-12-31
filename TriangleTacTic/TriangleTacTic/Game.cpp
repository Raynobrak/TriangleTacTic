#include "Game.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>

#include "board_constants.h"

Game::Game(PlayerType player1, PlayerType player2) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	window_.create({ WINDOW_SIZE, WINDOW_SIZE }, "TriangleTacTic", sf::Style::Close, settings);
	window_.setVerticalSyncEnabled(true);
	gameOver_ = false;

	p1_ = Player::createPlayerPtr(player1, coordinator_, window_);
	p2_ = Player::createPlayerPtr(player1, coordinator_, window_);

	initShapes();
}

void Game::start() {
	while (!gameOver_) {
		p1_->playTurn();
		p2_->playTurn();
		render();
	}
}

void Game::initShapes() {
	tile_.setSize({ TILE_WIDTH_REAL, TILE_HEIGHT_REAL });
	tile_.setOutlineThickness(TILES_OUTLINE_THICKNESS_N);
	tile_.setOutlineColor(TILES_OUTLINE_COLOR);
	tile_.setFillColor(TILES_COLOR);

	halfCross_.setSize({ TILE_WIDTH_REAL * SYMBOLS_WIDTH_N, SYMBOLS_THICKNESS_N * TILE_WIDTH_REAL });
	halfCross_.setPosition(tile_.getPosition() + sf::Vector2f(TILE_WIDTH_REAL, TILE_HEIGHT_REAL) / 2.f);
	halfCross_.setOrigin(halfCross_.getSize() / 2.f);
	halfCross_.setFillColor(CROSSES_COLOR);

	round_.setRadius(TILE_WIDTH_REAL * SYMBOLS_WIDTH_N / 2.f);
	round_.setOrigin(sf::Vector2f(round_.getRadius(), round_.getRadius()));
	round_.setFillColor(sf::Color::Transparent);
	round_.setOutlineThickness(-SYMBOLS_THICKNESS_N * TILE_WIDTH_REAL);
	round_.setOutlineColor(ROUNDS_COLOR);

	triangle_.setPointCount(3);
	triangle_.setRadius(TILE_WIDTH_REAL * SYMBOLS_WIDTH_N / 2.f);
	triangle_.setOrigin(sf::Vector2f(triangle_.getRadius(), triangle_.getRadius()));
	triangle_.setFillColor(sf::Color::Transparent);
	triangle_.setOutlineColor(TRIANGLES_COLOR);
	triangle_.setOutlineThickness(-SYMBOLS_THICKNESS_N * TILE_WIDTH_REAL);
}

void Game::render() { 
	const auto& board = coordinator_.getReadonlyBoard();

	window_.clear(BACKGROUND_COLOR);

	sf::Vector2f boardStart = BOARD_MARGIN_N * sf::Vector2f(static_cast<float>(WINDOW_SIZE), static_cast<float>(WINDOW_SIZE));

	for (pos_component_t line = 0; line < Board::UINT_BOARD_WIDTH; ++line) {
		for (pos_component_t col = 0; col < Board::UINT_BOARD_WIDTH; ++col) {

			tile_.setPosition(boardStart + sf::Vector2f(col * TILE_WIDTH_REAL, line * TILE_HEIGHT_REAL));
			window_.draw(tile_);

			Symbol symbolOnTile = coordinator_.getReadonlyBoard().getSymbolAt({ col,line });

			switch (symbolOnTile) {
				case Symbol::Crosses: {
					halfCross_.setPosition(tile_.getPosition() + HALF_TILE_SIZE);
					halfCross_.setRotation(45.f);
					window_.draw(halfCross_);
					halfCross_.setRotation(-45.f);
					window_.draw(halfCross_);
					break;
				}	
				case Symbol::Rounds: {
					round_.setPosition(tile_.getPosition() + HALF_TILE_SIZE);
					window_.draw(round_);
					break;
				}

				case Symbol::Triangles: {
					triangle_.setPosition(tile_.getPosition() + HALF_TILE_SIZE);
					triangle_.move({ 0.f, SYMBOLS_THICKNESS_N * TILE_WIDTH_REAL });
					window_.draw(triangle_);
					break;
				}
			}
		}
	}

	window_.display();
}
