#pragma once
#include<vector> 
#include<string>
#include"player.h"

typedef struct ActionMsg{
    ActionFmt action_fmt;
    int user_idx;    
}ActionMsg;

typedef struct SessionMsg{
    std::vector<Card> public_cards;
    Session session;
}SessionMsg;

class Table{
private:
	int pot;
	std::vector<int> alive_idx;
	std::shared_ptr<vector<Player>> players;
	std::vector<Card> public_cards;
	Table();
	Table(std::shared_ptr<vector<Player>> players,int pot);
public:
	bool update(const ActionMsg& action_msg);
	bool update(const SessionMsg& session_msg);
	void display();
	static std::shared_ptr<Table> create(std::shared_ptr<vetor<Player>> players, int pot);
};
