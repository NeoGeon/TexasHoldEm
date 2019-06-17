#include<iostream>
#include<string>
#include<cstdio>
#include"type.h"
#include"deck.h"
using namespace std;
void testCase();
string typeFmt[9]={"straitFlush", "FourOfKind", "FullHouse", "Flush", "Strait", "ThreeOfKind", "TwoPairs", "OnePairs","highCards"};
int main(){
    /*
    DeckTexas d;
    d.shuffle();
    //d.printCards();
    vector<Card> hole;
    vector<Card> board;
    for(int i=0;i!=2;i++){
        Card card = d.draw();
        hole.push_back(card);
        cout<<"card: "<<card.Fmt()<<endl;
    }
    for(int i=0;i!=5;i++){
        Card card=d.draw();
        board.push_back(card);
        cout<<"card: "<<card.Fmt()<<endl;
    }
    Hand hand(hole,board);
    cout<<"the Type:"<<hand.Type()<<endl;
    for(auto it=hand.finalCards.begin();it!=hand.finalCards.end();it++){
        cout<<it->Fmt()<<",";
    }
    cout<<endl;
    */
    testCase();
    return 0;
}
void testCase(){
    Card c1(spade, 2);
    Card c2(spade, 3);
    Card c3(club, 4);
    Card c4(club, 5);
    Card c5(heart, 6);
    Card c6(spade,8);
    Card c7(diamond, 9);
    vector<Card> hole(2);
    vector<Card> board(5);
    hole[0] = c1;
    hole[1] = c2;
    board[0] = c3;
    board[1] = c4;
    board[2] = c5;
    board[3] = c6;
    board[4] = c7;
    Hand hand(hole, board);
    cout<<"the Type:"<<typeFmt[hand.Type()]<<endl;
    for(auto it=hand.finalCards.begin();it!=hand.finalCards.end();it++){
        cout<<it->Fmt()<<",";
    }
    cout<<endl;
} 
