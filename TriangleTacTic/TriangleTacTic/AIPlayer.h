#pragma once
#include "Player.h"
class AIPlayer : public Player {
public:
	AIPlayer(GameCoordinator& coordinator);
	void playTurn() override;
private:

};

