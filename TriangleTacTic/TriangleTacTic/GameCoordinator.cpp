#include "GameCoordinator.h"

GameCoordinator::GameCoordinator() : nextSymbolToPlay_(Symbol::None) {}

bool GameCoordinator::hasRightToPlay(Symbol s) const {
	return s == nextSymbolToPlay_ || nextSymbolToPlay_ == Symbol::None;
}

bool GameCoordinator::makeMove(Symbol s, TilePosition pos) {
	if (hasRightToPlay(s)) {
		if (board_.placeSymbolAt(pos, s)) {
			nextSymbolToPlay_ = nextSymbol();
			return true;
		}
	}
	
	return false;
}

const Board& GameCoordinator::getReadonlyBoard() const {
	return board_;
}

Symbol GameCoordinator::nextSymbol() const
{
	switch (nextSymbolToPlay_) {
	case Symbol::Crosses:
		return Symbol::Rounds;
	case Symbol::Rounds:
		return Symbol::Crosses;
	case Symbol::Triangles:
		throw std::logic_error("The game coordinator cannot determine which symbol has to play because triangles can be placed by both players.");
	case Symbol::None:
		throw std::logic_error("The game coordinator cannot determine which symbol has to play if none has played already.");
	}
}
