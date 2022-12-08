#pragma once

#include "game_config.hxx"
#include "ship.hxx"
#include <iostream>

struct Board
{
    using Grid_vector = std::vector<std::vector<std::vector<bool>>>;
    using Position = ge211::Posn<int>;

public:
    Board(Position tl);

    Grid_vector get_grid();

    bool is_empty();

    void shuffle(std::vector<Ship> ships);

    bool place_ships(Ship ship, Position grid_pos);

    void clear_grid();

    void destroy_all_ships();

    Position screen_to_board(Position position);

    std::vector<bool> on_clicked(Position pos);

    int get_clicks() const;

    // For testing
    Position get_random_ship_pos() const;
    Position get_random_water_pos() const;
    std::vector<bool> on_clicked_board(Position pos);

private:
    // bool grid for checking if there is ship placed on there
    // Each tile will hold the following: 1. been_clicked, 2. is_ship_tile,
    // 3. has_ship
    Grid_vector grid_template = std::vector<std::vector<std::vector<bool>>>(15,
                                                                     std::vector<std::vector<bool>>(8,
                                                                                                       std::vector<bool>(3, false)));
    Grid_vector& grid;
    Game_config config_;
    Position top_left;
    int clicks_;
};