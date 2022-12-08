#include "board.hxx"
#include <stdlib.h>


Board::Board(Position tl)
        :grid(grid_template),
         top_left(tl),
         clicks_(0)
{}





Board::Grid_vector
Board::get_grid()
{
    return grid;
}

bool
Board::is_empty()
{
    for (std::vector<std::vector<bool>> vect : grid){
        for (std::vector<bool> tile_info : vect){
            if (tile_info[2]) {
                return false;
            }
        }
    }
    return true;
}

void
Board::shuffle(std::vector<Ship> ships)
{
    clear_grid();
    for (Ship ship: ships){
        bool success = false;
        while (!success) {
            int x = (rand() % 15);
            int y = (rand() % 8);
            Position random_pos = {x,y};
            success = place_ships(ship, random_pos);
        }
    }
}

bool
Board::place_ships(Ship ship, Position grid_pos)
{
    ge211::geometry::Dims<int> ship_dims = ship.get_dims();
    int max_col = grid_pos.x + (ship_dims.width - 1);
    int max_row = grid_pos.y + (ship_dims.height -1);

    if (grid_pos.x < 15 && grid_pos.y < 8 && max_col < 15 && max_row < 8) {
        // Run through and make sure positions are empty
        for (int i = grid_pos.x; i <= max_col; i++){
            for (int j = grid_pos.y; j <= max_row; j++){
                if (grid[i][j][2]) {
                    return false;
                }
            }
        }

        // Fill positions (if they were empty)
        for (int i = grid_pos.x; i <= max_col; i++){
            for (int j = grid_pos.y; j <= max_row; j++){
                grid[i][j][2] = true;
                grid[i][j][1] = true;
            }
        }
        return true;
    } else {
        return false;
    }
}

void
Board::clear_grid()
{
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 8; j++){
            grid[i][j][2] = false;
            grid[i][j][1] = false;
            grid[i][j][0] = false;
        }
    }
}

ge211::Posn<int>
Board::screen_to_board(Position position)
{
    Position board_pos{(position.x - top_left.x) / 35, (position.y - top_left.y) / 35};

    if (board_pos.x > 14 || board_pos.x < 0 || board_pos.y > 7 || board_pos.y
                                                                  < 0) {
        board_pos = {-1, -1};
    }

    return board_pos;
}

std::vector<bool>
Board::on_clicked(Position pos)
{
    Position invalid_pos = {-1, -1};
    pos = screen_to_board(pos);
    if (pos != invalid_pos) {
        if (!grid[pos.x][pos.y][0]) {
            if (grid[pos.x][pos.y][2]) {
                grid[pos.x][pos.y][2] = false;
            }

            grid[pos.x][pos.y][0] = true;
            clicks_++;

            return {true, grid[pos.x][pos.y][1]};
        }
    }

    return {false, false};
}

void
Board::destroy_all_ships()
{
    for (std::vector<std::vector<bool>>& vect : grid){
        for (std::vector<bool>& tile_info : vect){
            if (tile_info[2]) {
                tile_info[2] = false;
            }
        }
    }
}

int
Board::get_clicks() const
{
    return clicks_;
}

Board::Position
Board::get_random_ship_pos() const
{
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 8; j++){
            if (grid[i][j][2]) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

Board::Position
Board::get_random_water_pos() const
{
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 8; j++){
            if (!grid[i][j][0] && !grid[i][j][1] && !grid[i][j][2]) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

std::vector<bool>
Board::on_clicked_board(Board::Position pos)
{
    Position invalid_pos = {-1, -1};

    if (pos != invalid_pos) {
        if (!grid[pos.x][pos.y][0]) {
            if (grid[pos.x][pos.y][2]) {
                grid[pos.x][pos.y][2] = false;
            }

            grid[pos.x][pos.y][0] = true;
            clicks_ += 1;

            std::cout << clicks_;

            return {true, grid[pos.x][pos.y][1]};
        }
    }

    return {false, false};
}
