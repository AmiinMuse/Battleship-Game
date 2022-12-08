#include "game_config.hxx"

// This is the default (and only) constructor for `Game_config`. It
// determines all the default values of all the member variables.
Game_config::Game_config()
        : screen_dims(700, 700),
          brick_dims(25, 25),
          grid_spacing(10, 10),
          button_dims(150, 30),
          P1_board_pos(110, 40),
          P2_board_pos(110, 400)
{
    ship_types = {{3, 1},
                  {1,3},
                  {4, 1},
                  {1, 2}};
}