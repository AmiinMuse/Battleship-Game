#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "game_config.hxx"
#include "ship.hxx"
#include <iostream>



class Model
{

public:

    Model();

    Game_config config_;

    using Position = ge211::Posn<int>;

    enum Players {
        P1,
        P2,
        neither
    };

    Board get_player_board(Players player) const;

    bool check_active() const {
        return active_;
    }

    bool is_game_over() const {
        return game_over_;
    }

    bool board_placement() const{
        return board_placement_;
    }

    Players board_placement_player() const{
        return board_placement_player_;
    }

    Players get_turn() {
        return turn_;
    }

    void start_placement(Players player);

    void grid_clicked(Position position);

    void stop_placement();

    void start_game();

    void shuffle_board();

    void check_game_over();
    void force_game_over(Players winner);

    std::string get_winner() const;
    float get_winner_score() const;

    void change_turn();

    Player get_player1() const;
    Player get_player2() const;

    // For testing
    void grid_clicked_board(Position position);

private:
    bool active_;
    bool game_over_;
    bool board_placement_;

    Players turn_;
    Players board_placement_player_;
    Players winner_;

    Player player1;
    Player player2;
};