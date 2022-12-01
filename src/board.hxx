#pragma once

#include <ge211.hxx>
#include <vector>
#include "game_config.hxx"
#include "ship.hxx"


struct Board
{
    using Grid_vector = std::vector<std::vector<bool>>;
    public:
        Board();

        using Position = ge211::Posn<int>;


        Grid_vector get_grid();

        bool is_empty();

        void shuffle(std::vector<Ship> ships);

        bool place_ships(Ship ship, Position grid_pos);

        void clear_grid();

    private:
        // bool grid for checking if there is ship placed on there
        Grid_vector grid;
        Game_config config_;
};