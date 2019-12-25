#include "GameCoordinator.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "Player.h"

#include <memory>

class Game
{
public:
	Game(PlayerType player1, PlayerType player2);
	void start();
private:
	sf::Vector2f getWindowSize() const;

	void render();

	GameCoordinator coordinator_;
	sf::RenderWindow window_;
	bool gameOver_;

	std::unique_ptr<Player> p1_;
	std::unique_ptr<Player> p2_;
};

