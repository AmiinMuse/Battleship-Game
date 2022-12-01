#include "board.hxx"
#include <stdlib.h>

Board::Board()
{
    grid = std::vector<std::vector<bool>>(15, std::vector<bool>(8, false));
    //srand(time(0));
}
//is there a ship --> diff board
//did they click--> one board --> to interact with view

//board for color and board for ship locations (just trues and false)

//one is changing numbers for color drawing




Board::Grid_vector
Board::get_grid()
{
    return grid;
}

bool
Board::is_empty()
{
    for (std::vector<bool> vect : grid){
        for (bool tile: vect){
            if (tile) {
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
    int max_col = grid_pos.x + (ship.get_dims().width - 1);
    int max_row = grid_pos.y + (ship.get_dims().height -1);

    if (grid_pos.x < 15 && grid_pos.y < 8 && max_col < 15 && max_row < 8) {
        // Run through and make sure positions are empty
        for (int i = grid_pos.x; i <= max_col; i++){
            for (int j = grid_pos.y; j <= max_row; j++){
                if (grid[i][j]) {
                    return false;
                }
            }
        }

        // Fill positions (if they were empty)
        for (int i = grid_pos.x; i <= max_col; i++){
            for (int j = grid_pos.y; j <= max_row; j++){
                grid[i][j] = true;
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
            grid[i][j] = false;
        }
    }
}

