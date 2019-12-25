#pragma once

constexpr float BOARD_MARGIN = 0.1f;
constexpr float BOARD_WIDTH = 1.f - 2.f * BOARD_MARGIN;
constexpr float TILE_WIDTH = BOARD_WIDTH / static_cast<float>(Board::UINT_BOARD_WIDTH);