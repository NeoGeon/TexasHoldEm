#ifndef __TEXAS_H_
#define __TEXAS_H_
#include<string>
#include<vector>
#include"deck.h"
#include"infoQ.h"
enum TexasPhase{
    preFlop,
    Flop,
    Turn,
    River,
    Final
};
enum TexasAction{
    Check,
    Fold,
    Call,
    Raise,
    All_in,
    All_in_call
};
enum TexasSuitPattern{
    StraitFlush,
    FourOfKind,
    Fullhouse,
    Flush,
    Strait,
    TreeOfKind,
    TwoPairs,
    OnePair,
    HighCard
};

class Player{
private:
    vector<Cards> hand;
    int chips;
    TexasAction action;
    bool in_pot;
    InfoQueue& queue;
public:
    Player(InfoQueue&);
    ~Player();
    void startNewRound();
    void getCard();
    void addChips(int pot);
    bool isAlive();
    TexasAction action();
    void sit();
};
class TexasHoldEm{
private:
    vector<Player> players;
    vector<Cards> publicCards;
    map<TexasSuitPattern, int> suitCompare;
    map<int, int> numberCompare;
    Deck deck;
    int dealer;
    int utg;
    int sb;
    int bb;
    int sbCount; 
    int tableMin;
    int tableMax;
    int winner; 
    long long pot;
    const static int playerMax=7;
    InfoQueue& queue;


    bool CardNumberIsBigger(Card card1. Card card2);
    bool NumberIsBigger(vector<Card> suit1, vector<Card> suit2);
    bool SuitPatternIsBigger(vector<Card> suit1, vector<Card> suit2);
    bool SuitPatternIsBigger(TexasSuitPattern p1, TexasSuitPattern p2);
    TexasSuitPattern SuitPattern(vector<Card> suit);

    bool IsStrait(vector<Card> suit, bool sorted=false);
    bool IsFlush(vector<Card> suitm bool sorted=false);
    bool IsFourOfKind(vector<Card> suit, bool sorted=false);
    bool IsThreeOfKind(vector<Card> suit, bool sorted=false);
    bool IsTwoPairs(vector<Card> suit, bool sorted=false);
    bool IsFullHouse(vector<Card> suit, bool sorted=false);
    bool IsOnePair(vector<Card> suit, bool sorted=false);
    bool IsStaitFlush(vector<Card> suit. bool sorted=false);

    void initRule();
    void initTable();
    bool CheckWinnerByFold();
    bool CheckWinnerFinal();
    vector<Card>& FinalCards(vector<Card> cards);
    void sortCard(vector<Card> suit);
public:
    TexasHoldEm(InfoQueue& q);
    TexasHoldEm(int playerNum, int sbCount, InfoQueue& q);
    //TexasHoldEm(int playerNum, int sbCount, tableMin, tableMax);
    ~TexasHoldEm();
    void display();
    void addPlayer();
    void deletePlayer();
    void oneRound();
}; 

#endif
