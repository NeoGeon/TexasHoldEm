#include "TexasSession.h"

namespace TexasSession {

bool PreFlopSession::Loop() {
    auto card_3 = table->deck->draw();
    SessionMsg sess_msg = {std::vector<Card>(), PREFLOP};
    table->update(sess_msg);
    bool end_game = false;
    auto idx = table->first;
    BetLoop(idx, end_game);
    return end_game;
}

bool FlopSession::Loop() {
    auto card_1 = table_deck->draw();
    auto card_2 = table_deck->draw();
    auto card_3 = table_deck->draw();
    SessionMsg sess_msg {std::vector<Card>({card_1, card_2, card_3}), FLOP};
    table->update(sess_msg);
    bool end_game = false;
    auto idx = table->first;
    BetLoop(idx, end_game);
    return end_game;
}


bool TurnSession::Loop() {
    auto card_4 = table_deck->draw();
    SessionMsg sess_msg {std::vector<Card>({card_4}), TURN};
    table->update(sess_msg);
    bool end_game = false;
    auto idx = table->first;
    BetLoop(idx, end_game);
    return end_game;
}

bool RiverSession::Loop() {
    auto car_5 = table_deck->draw();
    SessionMsg sess_msg {std::vector<Card>(card_5), RIVER};
    table->update(sess_msg);
    bool end_game = false;
    auto idx = table->first;
    BetLoop(idx, end_game);
    return end_game;  
}

}
