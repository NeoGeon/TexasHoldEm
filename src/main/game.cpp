#include "game.h"
#include "info.h"
#include "PreSession.h"
#include "FlopSession.h"
#include "TurnSession.h"
#include "RiverSession.h"
Game::Game(int sb, int bb, int max_players) : sb(sb), bb(bb), max_players(max_players) {
    players = std::make_shared<vector>();
    players->resize(max_players);
    total_pot = 0;
}

static std::shared_ptr<Game> Game::createGame(int sb, int bb, int max_players) {
    return std::make_shared<Game>(sb, bb, max_players);
}

bool run(){
    while (true) {
         auto tablePtr = Table::create(players, sb+bb);
	 auto pre_session_ptr = std::make_shared<PreSession>(players, tablePtr);
	 auto flop_session_ptr = std::make_shared<FlopSession>(players, tablePtr);
	 auto turn_session_ptr = std::make_shared<TurnSession>(players, tablePtr);
	 auto river_session_ptr = std::make_shared<RiverSession>(players, tablePtr);
	 auto session_ptr_vec = std::vector<std::shared_ptr<BaseSession>>(pre_session_ptr,
			 flop_session_ptr, turn_session_ptr, river_session_ptr);
	 for (const auto& session_ptr : session_ptr_vec) {
	     if (session_ptr->Loop()) {
		  continue;
	     }
	 }
    }
    return true;
}

