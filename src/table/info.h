#pragma once
#include<vector> 
#include<string>
#include "player.h"
#include "gameDef.h"

typedef struct ActionMsg{
    Action action;
    int user_idx;    
}ActionMsg;

typedef struct SessionMsg{
    std::vector<Card> public_cards;
    Session session;
}SessionMsg;

class Table{
private:
	int pot;
	Session current_session;
	std::vector<int> alive_idx;
	std::shared_ptr<vector<Player>> players;
	std::vector<Card> public_cards;
	Table();
	Table(std::shared_ptr<vector<Player>> players,int pot);
public:
	int first_action_pos();
	bool update(const ActionMsg& action_msg);
	bool update(const SessionMsg& session_msg);
	void display();
	static std::shared_ptr<Table> create(std::shared_ptr<vetor<Player>> players, int pot);
};
