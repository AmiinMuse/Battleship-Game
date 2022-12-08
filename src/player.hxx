#pragma once

#include "board.hxx"

struct Player {
    using Dimensions = ge211::Dims<int>;
    using Position = ge211::Posn<int>;

public:
    Player(Position tl);

    Board get_board() const;

    void shuffle();

    float get_score() const;



private:
    Board board;
    Game_config config;
    std::vector<Ship> ships;
    std::vector<int> score_;
};