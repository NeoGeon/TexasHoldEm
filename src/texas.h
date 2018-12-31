#ifndef __TEXAS_H_
#define __TEXAS_H_
#include<string>
#include<vector>
#include"deck.h"
enum TexasPhase{
    preFlop,
    Flop,
    Turn,
    River,
    Final
};
class Player{
private:
    vector<Cards> hand;
    int chips;
public:
    Player();
    ~Player();
    void getCard();
    void addMoney();
    void sit();
};
class TexasHoldEm{
private:
    vector<Player> players;
    vector<Cards> publicCards;
    Deck deck;
    int dealer;
    int sb;
    int bb;
    int sbCount; 
    int tableMin;
    int tableMax; 
    long long pot;
    const static int playerMax=7;
public:
    TexasHoldEm();
    TexasHoldEm(int playerNum, int sbCount);
    TexasHoldEm(int playerNum, int sbCount, tableMin, tableMax);
    ~TexasHoldEm();
    void display();
    void addPlayer();
    void deletePlayer();
    void oneRound();
}; 

#endif
