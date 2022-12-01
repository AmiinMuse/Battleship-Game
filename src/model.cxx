#include "model.hxx"

Model::Model()
    :config_(),
    turn_(neither),
    active_(false),
    game_over_(false),
    board_placement_(false),
    board_placement_player_(neither),
    player1(),
    player2()


{}

Board
Model::get_player_board(Model::Players player) const
{
    if (player == Model::Players::P1){
        return player1.get_board();
    } else{
        return player2.get_board();
    }
}

void
Model::start_placement(Model::Players player)
{
    board_placement_ = true;
    board_placement_player_ = player;
}

void
Model::stop_placement()
{
    board_placement_ = false;
    board_placement_player_ = Model::Players::neither;
}

void
Model::start_game()
{
    if (!player1.get_board().is_empty() && !player2.get_board().is_empty()){
        active_ = true;
    }
}

void
Model::shuffle_board()
{
    if (board_placement_player_ == Model::Players::P1){
        player1.shuffle();
    } else if (board_placement_player_ == Model::Players::P2){
        player2.shuffle();
    }
}

// void
// Model::set_game_over(Players player)
// {
//     if(player == Players::P1)
//     {
//         Board p_board = get_player_board(Players::P1);
//         if(p_board.is_empty())
//         {
//             active_ = false;
//         }
//     }
//     else
//     {
//         Board p2_board = get_player_board(Players::P2);
//         if(p2_board.is_empty())
//         {
//             active_ = false;
//         }
//     }
// }

bool
Model::hit_ship(Players player, Position pos)
{
    if(player == Players::P1)
    {
        Board p_board = get_player_board(player);
        Board::Grid_vector p_grid = p_board.get_grid();
        std::vector<ge211::Posn<int>> ship_locations{};
        //use i and j so you have the actual posn
        for(std::vector<bool> vect : p_grid)
        {
            for(bool tile : vect)
            {
                if(tile)
                {
                    ge211::Posn<int> p_pos = view_.screen_to_board(tile);
                    ship_locations.push_back(p_pos);
                }
                for(ge211::Posn<int> new_pos : ship_locations)
                {
                    if(pos != new_pos)
                    {
                        turn_ = Players::P2;
                        return false;
                    }
                    else
                    {
                        tile = false;
                        return true;
                    }
                }
            }
        }
    }
    if(player == Players::P2)
    {
        Board p2_board = get_player_board(player);
        Board::Grid_vector p2_grid = p2_board.get_grid();

        for(std::vector<bool> vect : p2_grid)
        {
            for(bool tile : vect)
            {
                if(//the tile pos is !equal to the pos that user clicks then
                    // didnt hit ship return false and keep tile = true)

                        {
                                turn_ = Players::P1;
                                return false;
                        }
                else
                {
                    tile = false;
                    return true;
                }
            }
        }
    }


}



// void
// Model::advance_turn(Players player, Position Pos)
// {
//     if(hit_ship())
//     turn_ = other_player(turn_);
// }


















