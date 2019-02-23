#ifndef __INFOQ_H_
#define __INFOQ_H_
#include<vector>
#include<texas.h>
struct TexasMessage{
    TexasAction action;
    int count;
}TexasMessage;

class InfoQueue{
private:
    vector<vector<TexasMessage>>  channel; 
    int totalCh;
public:
    InfoQueue(int ch);
    bool getInfo(int ch,TexasMessage& info);
    bool putInfo(int ch,TexasMessage info);
};

#endif
