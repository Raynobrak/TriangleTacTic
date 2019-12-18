#include "Board.h"

#include <algorithm>

Board::Board()
{
	reset();
}

TileState Board::getStateAt(size_t index) const
{
	if (index >= 0 && index < tiles_.size()) {
		return tiles_[index];
	}
	else {
		throw std::invalid_argument("index : out of range");
	}
}

TileState Board::getStateAt(size_t col, size_t line) const
{
	return getStateAt(coordsToIndex(col, line));
}

void Board::setStateAt(size_t index, TileState newState)
{
	tiles_[index] = newState;
}

void Board::setStateAt(size_t col, size_t line, TileState newState)
{
	setStateAt(coordsToIndex(col, line), newState);
}

void Board::reset()
{
	std::fill_n(tiles_, UINT_TILES_COUNT, TileState::Free);
}

size_t Board::coordsToIndex(size_t col, size_t line)
{
	return line * UINT_BOARD_WIDTH + col;
}
