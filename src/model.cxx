#include "model.hxx"

Model::Model()
        : config_(),
          active_(false),
          game_over_(false),
          board_placement_(false),
          turn_(neither),
          board_placement_player_(neither),
          winner_(neither),
          player1(config_.P1_board_pos),
          player2(config_.P2_board_pos)
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
        turn_ = Players::P1;
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

void
Model::change_turn()
{
    if (turn_ == Model::Players::P1){
        turn_ = Model::Players::P2;
    } else if (turn_ == Model::Players::P2){
        turn_ = Model::Players::P1;
    }
}

void
Model::grid_clicked(Position position)
{
    if (turn_ == Model::Players::P1){
        std::vector<bool> results = player2.get_board().on_clicked(position);
        if (results[0]) {
            if (!results[1]) {
                turn_ = Players::P2;
            }
        }
    } else if (turn_ == Model::Players::P2){
        std::vector<bool> results = player1.get_board().on_clicked(position);
        if (results[0]) {
            if (!results[1]) {
                turn_ = Players::P1;
            }
        }
    }

    check_game_over();
}

Player
Model::get_player1() const {
    return player1;
}

Player
Model::get_player2() const
{
    return player2;
}

void
Model::check_game_over()
{
    Board p1 = player1.get_board();
    Board p2 = player2.get_board();

    if (p1.is_empty() || p2.is_empty())
    {
        turn_ = Players::neither;
        active_ = false;
        game_over_ = true;

        if (p1.is_empty()) {
            winner_ = Players::P1;
        } else {
            winner_ = Players::P2;
        }
    }
}

void
Model::force_game_over(Players winner)
{
    if (winner == Players::P1) {
        player1.get_board().destroy_all_ships();
    } else if (winner == Players::P2) {
        player2.get_board().destroy_all_ships();
    }

    check_game_over();
}

std::string
Model::get_winner() const
{
    if (winner_ == Players::P1) {
        return "Player 1";
    } else if (winner_ == Players::P2) {
        return "Player 2";
    }

    return "Neither";
}

float
Model::get_winner_score() const
{
    if (winner_ == Players::P1) {
        return 10;
    } else if (winner_ == Players::P2) {
        return 12;
    }

    return 0;
}

void
Model::grid_clicked_board(Position position)
{
    if (turn_ == Model::Players::P1){
        std::vector<bool> results = player2.get_board().on_clicked_board
                (position);
        if (results[0]) {
            if (!results[1]) {
                turn_ = Players::P2;
            }
        }
    } else if (turn_ == Model::Players::P2){
        std::vector<bool> results = player1.get_board().on_clicked_board(position);
        if (results[0]) {
            if (!results[1]) {
                turn_ = Players::P1;
            }
        }
    }

    check_game_over();
}