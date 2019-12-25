#pragma once

#include <limits>

using pos_component_t = unsigned short;
struct TilePosition {
	pos_component_t col;
	pos_component_t line;
};

constexpr TilePosition UNDEFINED_POS = { std::numeric_limits<pos_component_t>::max(), std::numeric_limits<pos_component_t>::max() };