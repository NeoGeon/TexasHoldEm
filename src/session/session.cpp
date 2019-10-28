#include "session.h"

BaseSession::BaseSession(PlayerVecPtr players, TableInfoPtr table) : players(players), table(table) {};

bool BaseSession::BetLoop(int idx, bool end_game) {
    
}
