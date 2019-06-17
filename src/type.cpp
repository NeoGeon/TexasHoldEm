#include<vector>
#include<algorithm>
#include<iostream>
#include"deck.h"
#include"type.h"
using namespace std;
bool CardNumberIsSmaller( Card card1, Card card2){
     if (card1.Number() == 1)
         return false;
     else if(card2.Number() ==1)
         return true;
     return card1.Number()<card2.Number();
}

Hand::Hand(){};

Hand::Hand(vector<Card> cards){
    holeCards.push_back(cards[0]);
    holeCards.push_back(cards[1]);
    totalCards.push_back(cards[0]);
    totalCards.push_back(cards[1]);
}

Hand::Hand(vector<Card> card0, vector<Card> card1){
    holeCards.push_back(card0[0]);
    holeCards.push_back(card0[1]);
    totalCards.push_back(card0[0]);
    totalCards.push_back(card0[1]);
    for(auto it=card1.begin();it!=card1.end();it++){
        communityCards.push_back(*it);
        totalCards.push_back(*it);
    }
}

void Hand::GetBoard(Card card){
    communityCards.push_back(card);
    totalCards.push_back(card);
}

void Hand::GetFlop(vector<Card> cards){
    for(auto it=cards.begin();it!=cards.end();it++){
        communityCards.push_back(*it);
        totalCards.push_back(*it);
    }
}

TexasSuitPattern Hand::Type(){
     int state[7] = {0,0,0,0,0,0,0};  // flush, strait, fourofkind, fullhouse, threeOfKind, twoPair, onePair
     sort(totalCards.begin(), totalCards.end(), CardNumberIsSmaller);
     
     Colors flushColor;
     int Four;
     int three;
     int pairs[3] = {0};
     // check flush
     int color[4] = {0,0,0,0};
     for(auto it=totalCards.begin();it!=totalCards.end();it++){
         color[it->Color()]++;
         if(color[it->Color()]>=5){
             state[0]=1;
             flushColor = it->Color();
         }
     }

     //check strait
     int straitCnt = 0;
     for(auto it=totalCards.begin()+1;it!=totalCards.end();it++){
         if(it->Number()-(it-1)->Number()==1)
             straitCnt++;
             if(it->Number()==5 && (totalCards.end()-1)->Number()==1 && straitCnt==3){
                straitCnt++;
             }
         else if(it->Number()==1 && (it-1)->Number()==13 && straitCnt==3){
             straitCnt++;
         }else{
             straitCnt=0;
         }
         if(straitCnt==4){
            state[1]=1;
            break;
         }
     }

     // check four of a kind, fullhouse, set, two pair, pair
     int set[13]={0};
     for(auto it=totalCards.begin();it!=totalCards.end();it++){
        set[it->Number()-1]++;
     }
     int pairCnt = 0;
     for(int i=0;i!=13;i++){
         if(set[i]==4){
             state[2] = 1;
             Four = i+1;
         }
         if(set[i]==3){
             state[4] = 1;
             three = i+1;
         }
         if(set[i]==2){
             pairs[pairCnt] = i+1;
             pairCnt++;
             state[6]=1;
         }
     }
     if(pairCnt>=2)state[5]=1;
     if(state[4]==1 && state[6]==1)state[3]=1;

     //check straitFlush
     if(state[0]==1 && state[1]==1){
         vector<Card> flushes;
         for(auto it=totalCards.begin();it!=totalCards.end();it++){
             if(it->Color()==flushColor)flushes.push_back(*it);
         }  
         int cnt = flushes.size();
         int lastIndx=cnt-1;
         int straitCnt = 0;
         for(int i=cnt-2;i>=0;i--){
             if(flushes[i+1].Number()==1 && flushes[i].Number()==13){
                 straitCnt++;
             }
             if(flushes[i+1].Number()-1==flushes[i].Number()){
                 straitCnt++;
             }else{
                 straitCnt=0;
                 lastIndx=i;
             }
             if(straitCnt==4){
                 break;
             }
         }
         if(straitCnt==4){
            for(int i=lastIndx-4;i<=lastIndx;i++){
                finalCards.push_back(flushes[i]);
            }
            return StraitFlush;
         }
     }
    
     if(state[2]==1){
         if(totalCards[6].Number()==Four){
             finalCards.push_back(totalCards[2]);
             for(int i=6;i>=3;i--)finalCards.push_back(totalCards[i]);
         }else{
             finalCards.push_back(totalCards[6]);
             for(int i=0;i!=6;i++){
                 if(totalCards[i].Number()==Four)finalCards.push_back(totalCards[i]);
             }
         }
         return FourOfKind;
     }
     if(state[3]==1){
         for(int i=0;i!=7;i++){
             if(three==totalCards[i].Number())finalCards.push_back(totalCards[i]);
         }
         int thePair = -1;
         if(pairs[1]>pairs[0])thePair=pairs[1];
         else thePair=pairs[0];
         if(pairs[0]==1)thePair=1;
         for(int i=0;i!=6;i++){
             if(thePair==totalCards[i].Number())finalCards.push_back(totalCards[i]);
         }
         return FullHouse;
     }
     if(state[0]==1){
         int cnt = 5;
         for(int i=6;i>=0;i--){
             if(flushColor==totalCards[i].Color()){
                 finalCards.push_back(totalCards[i]);
                 cnt--;
                 if(cnt==0)return Flush;
             }
         }
     }
     if(state[1]==1){
         int lastIndx = 6;
         int straitCnt = 0;
         for(int i=5;i>=0;i--){
             if(totalCards[i].Number()==13 && totalCards[i+1].Number()==1)straitCnt++;
             if(totalCards[i].Number()==totalCards[i+1].Number()-1)straitCnt++;
             else{
                 lastIndx=i;
                 straitCnt=0;
             }
             if(straitCnt==4)break;
         } 
         for(int i=lastIndx;i>=lastIndx-4;i--){
             finalCards.push_back(totalCards[i]);
         }
         return Strait;
     }
     if(state[4]==1){
         for(int i=0;i!=7;i++){
             if(three==totalCards[i].Number())finalCards.push_back(totalCards[i]);
         }
         int cnt=0;
         for(int i=6;i>=0;i--){
             if(three!=totalCards[i].Number()){
                 finalCards.push_back(totalCards[i]);
                 cnt++;
                 if(cnt==2)return ThreeOfKind;
             }
         }
     }
     if(state[5]==1){
         int thePairs[2]={-1};
         if(pairs[2]==0){
            thePairs[0] = pairs[0];
            thePairs[1] = pairs[1];
         }else{
            if(pairs[0]==1){
                thePairs[0] = 1;
                
            }else{
                thePairs[0] = pairs[1];
            }
            thePairs[1] = pairs[2];
         }
         for(int i=6;i>=0;i--){
             if(totalCards[i].Number()==thePairs[0] || totalCards[i].Number()== thePairs[1]){
                 finalCards.push_back(totalCards[i]);
             }
         }
         for(int i=6;i>=0;i--){
             if(totalCards[i].Number()!=thePairs[0] && totalCards[i].Number()!=thePairs[1]){
                 finalCards.push_back(totalCards[i]);
                 return TwoPair;
             }
         }
     }
     if(state[6]==1){
         for(int i=0;i!=7;i++){
             if(totalCards[i].Number()==pairs[0]){
                 finalCards.push_back(totalCards[i]);
             }
         }
         int cnt=0;
         for(int i=6;i>=0;i--){
             if(totalCards[i].Number()!=pairs[0]){
                 finalCards.push_back(totalCards[i]);
                 cnt++;
                 if(cnt==3)return OnePair;
             }
         }
     }
     for(int i=6;i>=2;i--){
         finalCards.push_back(totalCards[i]);
     }
     return HighCard;
}

