#include "Game.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>

#include "board_constants.h"
#include <SFML/Graphics/CircleShape.hpp>

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

	window_.clear({50,50,50});

	sf::Vector2f boardStart = BOARD_MARGIN * sf::Vector2f(static_cast<float>(WINDOW_SIZE.x), static_cast<float>(WINDOW_SIZE.y));
	float tileWidth = TILE_WIDTH * WINDOW_SIZE.x;
	float tileHeight = TILE_WIDTH * WINDOW_SIZE.y;

	for (pos_component_t line = 0; line < Board::UINT_BOARD_WIDTH; ++line) {
		for (pos_component_t col = 0; col < Board::UINT_BOARD_WIDTH; ++col) {
			sf::RectangleShape tile;
			tile.setPosition(boardStart + sf::Vector2f(col * tileWidth, line * tileHeight));
			tile.setSize({ tileWidth, tileHeight });
			tile.setOutlineThickness(3.f);
			tile.setOutlineColor(sf::Color::Black);
			tile.setFillColor({ 250,250,100 });

			window_.draw(tile);

			auto symbolOnTile = coordinator_.getReadonlyBoard().getSymbolAt({ col,line });
			switch (symbolOnTile) {
			case Symbol::Crosses:
			{
				sf::RectangleShape stick1;
				stick1.setSize({ tileWidth * 0.6f, 7.f });
				stick1.setPosition(tile.getPosition() + sf::Vector2f(tileWidth, tileHeight) / 2.f);
				stick1.setOrigin(stick1.getSize() / 2.f);
				stick1.rotate(45.f);
				stick1.setFillColor(sf::Color::Magenta);
				sf::RectangleShape stick2 = stick1;
				stick2.setRotation(-45.f);
				window_.draw(stick1);
				window_.draw(stick2);
				break;
			}	
			case Symbol::Rounds:
			{
				sf::CircleShape round;
				round.setRadius(tileWidth * 0.6f / 2.f);
				round.setPosition(tile.getPosition() + sf::Vector2f(tileWidth, tileHeight) / 2.f);
				round.setOrigin(round.getRadius() * sf::Vector2f(1.f, 1.f));
				round.setFillColor(sf::Color::Magenta);
				window_.draw(round);
			}

			case Symbol::Triangles:
			{
				sf::CircleShape round;
				round.setPointCount(3);
				round.setRadius(tileWidth * 0.6f / 2.f);
				round.setPosition(tile.getPosition() + sf::Vector2f(tileWidth, tileHeight) / 2.f);
				round.setOrigin(round.getRadius() * sf::Vector2f(1.f, 1.f));
				round.setFillColor(sf::Color::Magenta);
				window_.draw(round);
			}
			}


		}
	}

	window_.display();
}
