#pragma once
#include <memory>
#include <vector>
#include "session.h"
#include "player.h"
class Game{
using SessionVecPtr = std::vector<std::shared_ptr<BaseSession>>;
using PlayerVecPtr = std::vector<std::shared_ptr<Player>>;
private:
	PlayerVecPtr players;
	int total_pot;
	Game();
	Game(int sb, int bb, int max_players);
	int sb;
	int bb;
	int max_players;
public:
	~Game();
	static createGame(int sb, int bb, int max_players);
	bool run();
};

