#pragma once
#include <memory>
#include <vector>
#include "player.h"
#include "Info.h"
class BaseSession{
using PlayerVecPtr = std::vector<std::shared_ptr<Player>>;
using TableInfoPtr = std::shared_ptr<TableInfo>;
private:
	PlayerVecPtr players;
	TableInfoPtr table;
public:
        BaseSession(PlayerVecPtr players, TableInfoPtr table)
	virtual bool Loop() = 0;  // handle event callback for user action
private:
	virtual bool draw() = 0;

};
