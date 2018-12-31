#ifndef __DECK_H_
#define __DECK_H_
#include<string>
#include<vector>
using namespace std;
enum Colors{
    spade,
    heart,
    club,
    diamond,
    joker
};

class Card{
private:
    Colors color_;
    int number_;
    string fmt;
    void fmtCalc();
public:
    Card();
    Card(const Card& c);
    Card(Colors col, int num);
    Card operator=(Card& card);
    int cardsRemain();
    bool noCards();
    Colors Color();
    int Number();
    ~Card();
    string Fmt();
};

class Deck{
protected:
    vector<Card> cards;
public:
    Deck();
    Card draw();
    void shuffle();
    void printCards();
    ~Deck();
};

class DeckTexas:public Deck{
private:
public:
    DeckTexas();
    //void shuffle();
    ~DeckTexas();
};


#endif
