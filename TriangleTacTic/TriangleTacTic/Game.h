#include "GameCoordinator.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "Player.h"

#include <memory>

class Game
{
public:
	Game(PlayerType player1, PlayerType player2);
	void start();
private:
	void initShapes();

	void render();

	GameCoordinator coordinator_;
	sf::RenderWindow window_;
	bool gameOver_;

	std::unique_ptr<Player> p1_;
	std::unique_ptr<Player> p2_;

	sf::RectangleShape tile_;
	sf::RectangleShape halfCross_;
	sf::CircleShape round_;
	sf::CircleShape triangle_;
};

