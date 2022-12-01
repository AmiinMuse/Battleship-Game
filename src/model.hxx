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
        using Board_pos = Board::Position;


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
        // ge211::Posn<int> screen_to_board(Position pos)
        // {
        //     ret
        // }

        void start_placement(Players player);

        bool hit_ship(Players player, Position Pos);



        void do_something_please();

        void stop_placement();

        void start_game();

        void shuffle_board();

        // void advance_turn();
        // void set_game_over(Players player);
        //Players other_player(Players player);

private:
        Players turn_;
        bool active_;
        bool game_over_;
        bool board_placement_;
        Players board_placement_player_;

        Player player1;
        Player player2;
};
