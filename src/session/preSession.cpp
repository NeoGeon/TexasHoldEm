#include "preSession.h"

bool PreFlopSession::Loop(){
    auto card_1 = table->deck->draw();
    auto card_2 = table->deck->draw();
    auto card_3 = table->deck->draw();
    table->apply(card_1, card_2, card_3);
    bool end_game = false;
    auto idx = table->utg;
    BetLoop(idx, end_game);
    return end_game;
}


