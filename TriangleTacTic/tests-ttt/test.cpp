#include "pch.h"

#include "../TriangleTacTic/GameCoordinator.h"

TEST(GameCoordinator, normal_gameplay) {
    GameCoordinator c;

	EXPECT_EQ(c.placeSymbolAt({ 0,0 }), MoveValidity::Valid);
	EXPECT_EQ(c.placeTriangleAt({ 0,1 }), MoveValidity::Valid);
	c.finishTurn();
	EXPECT_EQ(c.placeSymbolAt({ 0,2 }), MoveValidity::Valid);
	c.finishTurn();
	EXPECT_EQ(c.placeSymbolAt({ 0,3 }), MoveValidity::Valid);
}

TEST(GameCoordinator, monkey_gameplay) {
	GameCoordinator c;
	EXPECT_THROW(c.finishTurn(), std::logic_error);

	EXPECT_EQ(c.placeSymbolAt({ 0,1432 }), MoveValidity::OverlappingOrOutOfBounds);
	EXPECT_EQ(c.placeTriangleAt({ 0,1432 }), MoveValidity::OverlappingOrOutOfBounds);

	EXPECT_EQ(c.placeSymbolAt({ 0,0 }), MoveValidity::Valid);
	EXPECT_EQ(c.placeSymbolAt({ 1,1 }), MoveValidity::SymbolAlreadyPlaced);

	c.finishTurn();
	EXPECT_THROW(c.finishTurn(), std::logic_error);

	EXPECT_EQ(c.placeTriangleAt({ 0,1 }), MoveValidity::Valid);
	EXPECT_EQ(c.placeTriangleAt({ 0,2 }), MoveValidity::TriangleAlreadyPlaced);
	EXPECT_EQ(c.placeSymbolAt({ 0,1 }), MoveValidity::OverlappingOrOutOfBounds);
}