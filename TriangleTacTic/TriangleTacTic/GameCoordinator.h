#pragma once

#include "Board.h"
#include "MoveValidity.h"

//
// Represents the game "referee".
//
// This class prevents the players from putting the board/game into a incoherent state by ensuring that every move or decision they make is valid.
// Basically, this class contains the game logic and forces the player to respect the rules.
//
class GameCoordinator
{
public:
	GameCoordinator();

	const Board& getReadonlyBoard() const;

	void newGame();

	bool finishTurn();
	MoveValidity placeSymbolAt(TilePosition pos);
	MoveValidity placeTriangleAt(TilePosition pos);

private:
	Symbol nextSymbol() const;

	Board board_;

	Symbol currentPlayingSymbol_;
	bool symbolPlaced_;
	bool trianglePlaced_;
};

