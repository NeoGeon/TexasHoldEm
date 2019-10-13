#ifndef __GAME_H_
#define __GAME_H_
#include <memory>
#include <vector>
#include "session.h"
#include "player.h"
class Game{
using SessionVecPtr = std::vector<std::shared_ptr<BaseSession>>;
using PlayerVecPtr = std::vector<std::shared_ptr<Player>>;
private:
	SessionVecPtr sessions;
	PlayerVecPtr players;
	int total_pot;
public:
	Game(PlayerVecPtr players);
	~Game();
	bool run();
};

#endif
