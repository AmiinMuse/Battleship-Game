#include "player.hxx"

Player::Player(Position tl)
        : board(tl),
          ships(),
          score_(0)
{
    for (Dimensions dim : config.ship_types){
        ships.push_back(Ship(dim));
    }
}

Board
Player::get_board() const
{
    return board;
}

float
Player::get_score() const
{
    return board.get_clicks();
}

void
Player::shuffle()
{
    board.shuffle(ships);
}
