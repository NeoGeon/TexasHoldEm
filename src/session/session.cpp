#include "session.h"

namespace TexasSession {

BaseSession::BaseSession(PlayerVecPtr players, TableInfoPtr table) : players(players), table(table) {};

bool BaseSession::BetLoop(int idx, bool end_game) {
	end_game = false;
	int total_gamer = players->size();
	// try catch will deal later
    	if (idx >= total_gamer) {
		return false;    
	}	
	int cur_pos = idx;
	int action_pos = cur_pos;
	do {
		if (players[action_pos]->alive) {
		      auto action_msg = players[action_pos]->make_action();
		      table->upadte(action_msg);
		      update_cur_pos(action_msg, cur_pos);
		} 
		if (table->alive_gamers() == 1) {
		      end_game = true;
		      break;
		}
		action_pos = (action_pos + 1)%total_gamer;
	} while(cur_pos==action_pos);
	return true;
}

bool BaseSession::update_cur_pos(const ActionMsg& action_msg, int cur_pos) {
    if (action_msg.action == RAISE || action_msg.action == ALL_IN_RAISE) {
         cur_pos = action_msg.user_idx;
    }
    return true;
}

}
