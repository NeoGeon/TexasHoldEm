#ifndef __TYPE_H_
#define __TYPE_H_
#include<vector>
#include "deck.h"
using namespace std;
enum TexasSuitPattern{
    StraitFlush,
    FourOfKind,
    FullHouse,
    Flush,
    Strait,
    ThreeOfKind,
    TwoPair,
    OnePair,
    HighCard
};

class Hand{
public:
    vector<Card> holeCards;
    vector<Card> communityCards;
    vector<Card> finalCards;

    void GetBoard(Card card);
    void GetFlop(vector<Card> flop);
    TexasSuitPattern Type();
    Hand();
    Hand(vector<Card> holeCards, vector<Card> communityCards);
    Hand(vector<Card> holeCards);


private:
    vector<Card> totalCards;
    TexasSuitPattern type;

    //bool CardNumberIsBigger(Card card1, Card card2);
    //Hand();
    //Hand(vector<Card> holeCards, vector<Card> communityCards);
    //Hand(vector<Card> holeCards);

};

#endif
