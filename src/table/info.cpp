#include"info.h"

static std::shared_ptr<Table> Table::create(std::shared_ptr<vector<Player>> players, int pot) {
    return std::make_shared<Table>(players, pot);
}

Table::Table(std::shared_ptr<vector<Player>> players, int pot) : players(players), pot(pot){
}


