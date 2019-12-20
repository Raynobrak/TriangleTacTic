#pragma once

#include "Board.h"

//
// Represents the game "referee".
//
// This class ensures that the player moves are valid. 
// It also takes care of remembering which player has to play.
//
class GameCoordinator
{
public:
	GameCoordinator();

	// Returns true if the given symbol has to play.
	// NOTE : If it's the very first turn of the game, any symbol that tries to play first will be given the right to.
	bool hasRightToPlay(Symbol s) const;

	bool makeMove(Symbol s, TilePosition pos);

	const Board& getReadonlyBoard() const;
private:
	Symbol nextSymbol() const;

	Board board_;
	Symbol nextSymbolToPlay_;
};

