#pragma once

#include "board.hxx"
#include "game_config.hxx"

struct Player {
    public:
        Player();
        using Dimensions = ge211::Dims<int>;
        using Position = ge211::Posn<int>;

        Board get_board() const;
        std::vector<Ship> get_ships() const;

        void shuffle();

        float get_score();

        Player other_player();



    private:
        // Model model_;
        Board board;
        Game_config config;
        std::vector<Ship> ships;
        std::vector<int> score_;
};