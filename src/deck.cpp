#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<map>
#include"deck.h"
#include<cstdlib>
#include<algorithm>
using namespace std;
Card::Card(){};
Card::Card(Colors col, int num):color_(col), number_(num){
    fmtCalc();
};
/*Card Card::operator=(Card &card){
    color_=card.Color();
    number_=card.Number();
    fmt=card.Fmt();
}*/
Card::Card(const Card& c){
    color_=c.color_;
    number_=c.number_;
    fmt=c.fmt;
};

void Card::fmtCalc(){
    string colorFmt;
    string numFmt;
    switch(number_){
    case 11:
        numFmt="J";
        break;
    case 12:
        numFmt="Q";
        break;
    case 13:
        numFmt="K";
        break;
    case 1:
        numFmt="A";
        break;
    default:
        numFmt=to_string(number_);
        break;
    }
    switch(color_){
    case spade:
        colorFmt="spade   ";
        break;
    case heart:
        colorFmt="heart   ";
        break;
    case club:
        colorFmt="club    ";
        break;
    case diamond:
        colorFmt="diamond ";
        break;
    case joker:
        colorFmt="joker   ";
        if(number_==14){
            numFmt="small";
        }else{
            numFmt="big";
        }
        break;
    default:
        break;
    }
    fmt=colorFmt+numFmt;
}

Colors Card::Color(){return color_;};

int Card::Number(){return number_;};

string Card::Fmt(){return fmt;};

Card::~Card(){};

Deck::Deck(){
    Colors col[4]={spade, heart, club, diamond};
    for(int i=0;i!=13;i++){
        for(int j=0;j!=4;j++){
            Card c(col[j],i+1);
            cards.push_back(c);
        }
    }
    Card joker0(joker,14);
    Card joker1(joker, 15);
    cards.push_back(joker0);
    cards.push_back(joker1);
}

Deck::~Deck(){};

Card Deck::draw(){
    Card c=cards.back();
    cards.pop_back();
    return c;
}

bool Deck::noCards(){
    return cards.size()==0;
}

int Deck::cardsRemain(){
    return cards.size();
}

void Deck::shuffle(){
    srand((unsigned)time(NULL));
    int deckNum=cards.size();
    int seq[70];
    int result[70];
    for(int i=0;i!=deckNum;i++){
        seq[i]=i;
    }
    int iteration=30;
    for(int i=0;i!=iteration;i++){
        int partition=rand()%deckNum;
        int index=0;
        int head=0;
        int tail=partition;
        while(head!=partition&&tail!=deckNum){
           result[index]=seq[head];
           head++;index++;
           result[index]=seq[tail];
           tail++;index++;
        }
        while(head!=partition){
           result[index]=seq[head];
           index++;head++;
        }
        while(tail!=deckNum){
           result[index]=seq[tail];
           index++;tail++;
        }
        for(int i=0;i!=deckNum;i++){
            seq[i]=result[deckNum-1-i];
        }
    }
    /*test program
    for(int i=0;i!=deckNum;i++){
        cout<<seq[i]<<" ";
    }
    cout<<endl;
    sort(seq,seq+54);
    for(int i=0;i!=deckNum;i++){
        cout<<seq[i]<<" ";
    }
    cout<<endl;
    */
    /*shuffle asign*/
    vector<Card> mapper;
    for(int i=0;i!=deckNum;i++){
        mapper.push_back(cards[i]);
    }
    
    cards.clear();
    for(int i=0;i!=deckNum;i++){
        cards.push_back(mapper[seq[i]]);
    }
}

void Deck::printCards(){
    for(vector<Card>::iterator it=cards.begin();it!=cards.end();it++){
        cout<<it->Fmt()<<endl;
    }
}

DeckTexas::DeckTexas():Deck(){
    cards.pop_back();
    cards.pop_back();
}

/*void DeckTexas::shuffle(){
    ;
}*/

DeckTexas::~DeckTexas(){};

