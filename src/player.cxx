
#include "player.hxx"

Player::Player()
    :
    board(),
    ships(),
    score_()
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
Player::get_score()
{

    return 0;
}

std::vector<Ship>
Player::get_ships() const
{
    return ships;
}

void
Player::shuffle()
{
    board.shuffle(ships);
}

// Player other_player()
// {
//     // changes player turn
//     // if (model_.get_turn() == Model::Players::P1){
//     //     return Model::Players::P2;
//     // }
//     return 0;
// }

