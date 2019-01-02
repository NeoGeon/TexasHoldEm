#include<iostream>
#include<string>
#include<vector>
#include"deck.h"
#include"texas.h"
using namespace std;
Player::Player(){


}

TexasHoldEm::TexasHoldEm(){
    phase=preFlop;
    
}


bool TexasHoldEm::CheckWinnerByFold(){
     int count=0;
     int index=0;
     for(vector<Player>::iterator it=playes.begin();it!=players.end();it++){
         if(it->in_pot){
             count++;
             index++;
         }
     }
     if(count==1){
         winner=index;
         return true;
     }
     return false;
}

bool TexasHoldEm::CheckWinnerFinal(){

}

vector<Card>& TexasHoldEm::FinalCards(vector<Card> cards){
     

}

void TexasHoldEm:OneTurn(TexasPhase phase){ //修改public 牌堆，等待用户action
    // 发牌阶段
    switch(phase){
        case preFlop:{   
            for(int i=0;i!=2;i++)
                for(int j=0;j!=playerMax;j++){
                    Card  card=deck.draw(); 
                    players.push_back(card);
                }
            break;
        }
        case Flop:{
            for(int i=0;i!=3;i++){
                Card card=deck.draw();
                publicCards.push_back(card);
            }
            break;
        }
        case Turn:{
            Card card=deck.draw();
            publicCards.push_back(card);
            break;
        }
        case River:{
            Card card=deck.draw();
            publicCards.push_back(card);
            break; 
        }
        case Final:{
            break;
        }
        default:{
            // error
            cout<<"error"<<endl;
        }
    }

    // player desicion session
    int startPos=utg;
    int index=utg;
    do{
       if(checkWinnerByFold())break;
       TexasAction act=players[startPos].action();       
       if(act==Raise||act==All_in){
           startPos=index;
       }
       index++;
    }while(startPos==index);

}


void TexasHoldEm::oneRound(){
    
  
}



/* below is private aux function*/

bool TexasHoldEm::CardNumberIsBigger(Card card1, Card card2){
    return numberCompair[card1.Number()]>numberCompair[card2.Number()];

}

bool TexasHoldEm::IsStrait(vector<Card> suit, bool sorted){
    if(!sorted){
        sorted(suit.begin(), suit.end(), CardNumberIsBigger);
    }
    for(vector<Card>::iterator it=suit.begin()+1;it!=suit.end();it++){
        vector<Card>::iterator it0 = it-1; 
        if(it0->Number()-it->Number!=1){
            return false;
        }
    }
    return true;
}

bool TexasHoldEm::IsStraiFlush(vector<Card> suit, bool sorted){
    return IsFlush(suit,sorted)&&IsStrait(suit, sorted);
}

bool TexasHoldEm::IsFlush(vector<Card> suit, bool sorted){
    for(vector<Card>::iterator it=suit.begin()+1;it!=suit.end();it++){
        if(it->Color()!=suit.begin()->Color()){
            return false;
        }
    }
    return true;
}

bool TexasHoldEm::IsFourOfKind(vector<Card> suit, bool sorted){
    int a[13];
    for(vector<Card>::iterator it=suit.begin();it!=suit.end();it++){
        a[it->Color()]++;
    }
    for(int i=0;i!=13;i++){
        if(a[i]==4)return true;
    }
    return false;
}

bool TexasHoldEm::IsThreeOfKind(vector<Card> suit, bool sorted){
    int a[13];
    for(vector<Card>::iterator it=suit.begin();it!=suit.end();it++){
        a[it->Color()]++;
    }
    int three=0;
    int one=0;
    for(int i=0;i!=13;i++){
        if(a[i]==3)three++;
        if(a[i]==1)one++;
    }
    if(three==1&&one==2)return true;
    return false;
}

bool TexasHoldEm::IsFullHouse(vector<Card> suit, bool sorted){
    int a[13];
    for(vector<Card>::iterator it=suit.begin();it！=suit.end();it++){
        a[it->Color()]++;
    }
    int three=0;
    int two=0;
    for(int i=0;i!=13;i++){
        if(a[i]==3)three++;
        if(a[i]==2)two++;
    }
    if(three==1&&two==1)return true;
    return false;
}

int pairCounts(vector<Card>& suit){
    int a[13];
    for(vector<Card>::iterator it=suit.begin();it!=suit.end();it++){
        a[it->Color()]++;
    }
    int two=0;
    for(int i=0;i!=13;i++){
        if(a[i]==2)two++;
    }
    return two;
}

bool TexasHoldEm::IsTwoPairs(vector<Card> suit, bool sorted){
    int cnt=pairCounts(suit);
    if(cnt==2)return true;
    return false;
}

bool TexasHoldEm::IsOnePair(vector<Card> suit, bool sorted){
    int cnt=pairCounts(suit)
    if(cnt==1)return true;
    return false;
}

