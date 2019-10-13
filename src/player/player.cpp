#include<vector>
#include<string>
#include<iostream>
#include"deck.h"
#include"type.h"
#include"player.h"
using namespace std;
Action actionMapper[5] = {Check, Call, Raise, All_in, Fold};
Player::Player(int id, int c){
    sitId = id;
    chips = c;
}

int Player::ID(){
    return sitId;
}

int Player::Chips(){
    return chips;
}

void Player::GetHole(vector<Card> h){
    hole.clear();
    hole.push_back(h[0]);
    hole.push_back(h[1]);
}

ActionFmt Player::GetAction(int lastChips=0){
    int cinCnt = 3;
    ActionFmt ret;
    int actNum;
    int chipsNum;
    while(cinCnt!=0){
        cout<<"please action: 0 check; 1 call; 2 raise; 3 All_in; 4 Fold"<<endl;
        cin>>actNum>>chipsNum;
        //verify the action and correct it
        if(actNum==0){
            if(lastChips>0){
                cout<<"cannot check for lastChips>0"<<endl;
                continue;
            }
            chipsNum = 0;
            break;
        }else if(actNum==1){
            chipsNum=lastChips;
            if(chipsNum>=chips){
                actNum = 3;
                chipsNum = chips;
            }
            if(chipsNum>chips){
                actNum == 2;
            }
            break;
        }else if(actNum==2){
            if(chipsNum==chips){
                actNum = 3;
                break;
            }
            if(chipsNum==lastChips){
                actNum = 1;
                break;
            }
            if(chipsNum<lastChips){
                cout<<"cannot raise when chipsNum<lastChips"<<endl;
                continue;
            } 
            break;
        }else if(actNum==3){
            chipsNum = chips;
            break;
        }else{
            chipsNum = 0;
            break;
        }
    }
    ret.action = actionMapper[actNum];
    ret.count  = chipsNum;
    chips-=ret.count;
    return ret;
}

void Player::ChipsReturn(int c){
    chips+=c;
}

AIPlayer1::AIPlayer1(int id, int chips):Player(id, chips){};

ActionFmt AIPlayer1::GetAction(int lastChips=0){
    ActionFmt act;
    if(lastChips==0){
        act.action = actionMapper[0];
        act.count = 0;
    }else{
        if(lastChips>chips){
            act.action = actionMapper[3];
            act.count = chips;
        }else{
            act.action = actionMapper[2];
            act.count = lastChips;
        }
    }
    return act;
}
