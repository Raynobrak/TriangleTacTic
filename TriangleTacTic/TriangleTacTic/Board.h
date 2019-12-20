#pragma once

#include <array>
#include "Symbol.h"
#include "TilePosition.h"

//
// Represents the board on which the game takes place.
// The goal of this class is to encapsulate the accessing logic of the board.
//
// For example, the Board makes sure that you cannot overwrite someone else's move (by placing your symbol over it).
//
class Board {
public:
	Board();

	Symbol getSymbolAt(size_t index) const;
	Symbol getSymbolAt(TilePosition pos) const;

	bool placeSymbolAt(size_t index, Symbol symbol);
	bool placeSymbolAt(TilePosition pos, Symbol symbol);

	void reset();

	static constexpr pos_component_t UINT_BOARD_WIDTH = 5u;
	static constexpr pos_component_t UINT_TILES_COUNT = UINT_BOARD_WIDTH * UINT_BOARD_WIDTH;
private:
	static size_t coordsToIndex(pos_component_t col, pos_component_t line);

	std::array<Symbol, UINT_BOARD_WIDTH*UINT_BOARD_WIDTH> tiles_;
};

