#include<iostream>
#include<vector>
#include"infoQ.h"
#include"texas.h"
InfoQueue::InfoQueue(int ch){
    for(int i=0;i!=n;i++){
        vector<TexasMessage> vec;
        channel.push_back(vec);
    }
    totalCh = ch;
}

bool InfoQueue::getInfo(int ch, TexasMessage& info){
    if(ch>=totalCh){
        return false;
    }
    if(channel[ch].size()==0){
        return false;
    }
    info = channel[ch].pop_back();
    return true;
}

bool InfoQueue::putInfo(int ch,TexasMessage info){
    if(ch>=totalCh){
        return false;
    }
    channel[ch].push_back(info);
    return true;
}
