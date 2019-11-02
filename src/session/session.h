#pragma once
#include <memory>
#include <vector>
#include "player.h"
#include "Info.h"
class BaseSession{
using PlayerVecPtr = std::vector<std::shared_ptr<Player>>;
using TablePtr = std::shared_ptr<Table>;
using ConstTablePtr = const std::shared_ptr<Table>;
private:
	PlayerVecPtr players;
	TableInfoPtr table;
public:
        BaseSession(PlayerVecPtr players, ConstTablePtr table)
	virtual bool Loop() = 0;  // handle event callback for user action
	virtual ~BaseSession() = default;
private:
	bool betLoop(int idx, bool end_game);
	bool update_cur_pos(const ActionMsg& action_msg, int cur_pos);
};


