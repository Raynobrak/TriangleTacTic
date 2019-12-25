#include <SFML/Graphics/RenderWindow.hpp>
#include <sfml/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "Game.h"

int main() {
    Game game(PlayerType::Human, PlayerType::Human);
    game.start();
}
