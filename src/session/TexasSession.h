#pragma once
#include <memory>
#include <vector>
#include "session.h"
namespace Session {
using PlayerVecPtr = std::vector<std::shared_ptr<Player>>;
using TableInfoPtr = std::shared_ptr<TableInfo>
	
class PreFlopSession : public BaseSession{
public:
	bool Loop() override;
	virtual ~PreFlopSession() = default;
};

class FlopSession : public BaseSession {
public:
	bool Loop() override;
	virtual ~FlopSession() = default;
};

class TurnSession : public TurnSession {
public:
	bool Loop() override;
	virtual ~TurnSession() = default;
};

class RiverSession : public BaseSession {
public:
	bool Loop() override;
	virtual ~RiverSession() = default;
};

}
