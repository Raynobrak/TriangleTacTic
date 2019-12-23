#pragma once

//
// Basically an error code for moves.
// Used to tell the user if the wanted move was valid and if not, why ?
//
enum class MoveValidity {
	Valid,
	SymbolAlreadyPlaced,
	TriangleAlreadyPlaced,
	OverlappingOrOutOfBounds
};