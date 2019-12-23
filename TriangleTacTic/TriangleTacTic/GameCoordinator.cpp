#include "GameCoordinator.h"

GameCoordinator::GameCoordinator() {
	newGame();
}

const Board& GameCoordinator::getReadonlyBoard() const {
	return board_;
}

void GameCoordinator::newGame() {
	currentPlayingSymbol_ = Symbol::Crosses;
	symbolPlaced_ = false;
	trianglePlaced_ = false;
}

void GameCoordinator::finishTurn() {
	if (symbolPlaced_) {
		currentPlayingSymbol_ = nextSymbol();
		symbolPlaced_ = false;
		trianglePlaced_ = false;
	}
	else {
		throw std::logic_error("cannot finish the turn prematurely");
	}
}

MoveValidity GameCoordinator::placeSymbolAt(TilePosition pos) {
	if (!symbolPlaced_) {
		if (board_.placeSymbolAt(pos, currentPlayingSymbol_)) {
			symbolPlaced_ = true;
			return MoveValidity::Valid;
		}
		else {
			return MoveValidity::OverlappingOrOutOfBounds;
		}
	}
	else {
		return MoveValidity::SymbolAlreadyPlaced;
	}
}

MoveValidity GameCoordinator::placeTriangleAt(TilePosition pos) {
	if (!trianglePlaced_) {
		if (board_.placeSymbolAt(pos, Symbol::Triangles)) {
			trianglePlaced_ = true;
			return MoveValidity::Valid;
		}
		else {
			return MoveValidity::OverlappingOrOutOfBounds;
		}
	}
	else {
		return MoveValidity::TriangleAlreadyPlaced;
	}
}

Symbol GameCoordinator::nextSymbol() const
{
	switch (currentPlayingSymbol_) {
	case Symbol::Crosses:
		return Symbol::Rounds;
	case Symbol::Rounds:
		return Symbol::Crosses;
	default:
		throw std::logic_error("invalid symbol stored");
	}
}
