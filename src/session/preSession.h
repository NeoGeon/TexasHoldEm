#pragma once
#include <memory>
#include <vector>
#include "session.h"
class PreFlopSession : public BaseSession{
using PlayerVecPtr = std::vector<std::shared_ptr<Player>>;
using TableInfoPtr = std::shared_ptr<TableInfo>;
public:
	bool Loop() override;
private:
	virtual bool draw();
};
