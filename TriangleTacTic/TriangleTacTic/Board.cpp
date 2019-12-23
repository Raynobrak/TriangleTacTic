#include "Board.h"

#include <algorithm>

Board::Board() {
	reset();
}

Symbol Board::getSymbolAt(size_t index) const {
	return tiles_[index];
}

Symbol Board::getSymbolAt(TilePosition pos) const {
	return getSymbolAt(coordsToIndex(pos.col, pos.line));
}

bool Board::placeSymbolAt(size_t index, Symbol symbol) {
	if (index >= 0 && index < UINT_TILES_COUNT) {
		if (getSymbolAt(index) == Symbol::None) {
			tiles_[index] = symbol;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Board::placeSymbolAt(TilePosition pos, Symbol symbol) {
	return placeSymbolAt(coordsToIndex(pos.col, pos.line), symbol);
}

void Board::reset() {
	std::fill_n(tiles_.begin(), UINT_TILES_COUNT, Symbol::None);
}

size_t Board::coordsToIndex(pos_component_t col, pos_component_t line) {
	return line * UINT_BOARD_WIDTH + col;
}
