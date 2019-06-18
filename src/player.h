#ifndef __PLAYER_H_
#define __PLAYER_H_
#include<vector>
#include"deck.h"
#include"type.h"
enum Action{
    Check,
    Call,
    Raise,
    All_in,
    Fold
};

typedef struct ActionFmt{
    Action action;
    int count;
}ActionFmt;

class Player{
private:
    int chips;
    int sitId;
    vector<Card> hole;
public:
    
    Player(int id,int chips);
    int ID();
    int Chips();
    void GetHole(vector<Card> hole);
    ActionFmt GetAction(int lastChips);
    void ChipsReturn(int chips);    
};


class AIPlayer1:public Player{
private:
    int chips;
    int sitId;
    vector<Card> hole;
public:
    
    AIPlayer1(int id, int chips);
    ActionFmt GetAction(int lastChips);
};

#endif
