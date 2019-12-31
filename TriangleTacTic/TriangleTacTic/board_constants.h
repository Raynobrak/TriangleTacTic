#pragma once

constexpr unsigned int WINDOW_SIZE = 800u;

const sf::Color BACKGROUND_COLOR = { 50,50,50 };
const sf::Color TILES_COLOR = { 250,250,100 };
const sf::Color TILES_OUTLINE_COLOR = sf::Color::Black;
const sf::Color CROSSES_COLOR = { 240,40,80 };
const sf::Color ROUNDS_COLOR = { 30,148,194 };
const sf::Color TRIANGLES_COLOR = { 255,155,16 };

// Constants ending with _N are normalized, which means they are expressed as a percentage of a real size.
constexpr float TILES_OUTLINE_THICKNESS_N = 1.f;
constexpr float SYMBOLS_THICKNESS_N = 0.08f;
constexpr float SYMBOLS_WIDTH_N = 0.8f;
constexpr float BOARD_MARGIN_N = 0.1f;
constexpr float BOARD_WIDTH_N = 1.f - 2.f * BOARD_MARGIN_N;
constexpr float TILE_SIZE_N = BOARD_WIDTH_N / static_cast<float>(Board::UINT_BOARD_WIDTH);

constexpr float TILE_WIDTH_REAL = TILE_SIZE_N * WINDOW_SIZE;
constexpr float TILE_HEIGHT_REAL = TILE_SIZE_N * WINDOW_SIZE;

const sf::Vector2f HALF_TILE_SIZE = sf::Vector2f(TILE_WIDTH_REAL, TILE_WIDTH_REAL) / 2.f;