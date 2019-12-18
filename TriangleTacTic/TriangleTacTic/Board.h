#pragma once

#include <array>
#include "TileState.h"

constexpr size_t UINT_BOARD_WIDTH = 5u;
constexpr size_t UINT_TILES_COUNT = UINT_BOARD_WIDTH * UINT_BOARD_WIDTH;

class Board {
public:
	Board();

	TileState getStateAt(size_t index) const;
	TileState getStateAt(size_t col, size_t line) const;

	void setStateAt(size_t index, TileState newState);
	void setStateAt(size_t col, size_t line, TileState newState);

	void reset();
private:
	static size_t coordsToIndex(size_t col, size_t line);

	std::array<TileState, UINT_BOARD_WIDTH*UINT_BOARD_WIDTH> tiles_;
};

