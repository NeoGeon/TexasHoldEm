#include<iostream>
#include<string>
#include<cstdio>
#include"deck.h"
using namespace std;
int main(){
    DeckTexas d;
    cout<<"end init"<<endl;
    d.shuffle();
    d.printCards();
    for(int i=0;i!=5;i++){
        cout<<"draw:"<<d.draw().Fmt()<<endl;
    }
    return 0;
}
