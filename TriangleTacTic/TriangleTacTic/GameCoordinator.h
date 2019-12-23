#pragma once

#include "Board.h"
#include "MoveValidity.h"

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

	const Board& getReadonlyBoard() const;

	void newGame();

	void finishTurn();
	MoveValidity placeSymbolAt(TilePosition pos);
	MoveValidity placeTriangleAt(TilePosition pos);

private:
	Symbol nextSymbol() const;

	Board board_;

	Symbol currentPlayingSymbol_;
	bool symbolPlaced_;
	bool trianglePlaced_;
};

