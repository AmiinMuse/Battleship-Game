#include "controller.hxx"

Controller::Controller()
        : view_(model_),
          config_()
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

Controller::Dimensions
Controller::initial_window_dimensions() const
{
    return config_.screen_dims;
}


std::string
Controller::initial_window_title() const
{
    return "Battleship";
}



void
Controller::on_mouse_down(ge211::Mouse_button mouse, ge211::Posn<int> position)
{
    if (!model_.check_active() && !model_.is_game_over() &&
        !model_.board_placement()) {
        // player one button pressed
        if (position.x > 250 && position.x < 400) {
            if (position.y > 250 && position.y < 280) {
                model_.start_placement(Model::Players::P1);
            }
        }
        //player 2 button pressed
        if (position.x > 250 && position.x < 400) {
            if (position.y > 320 && position.y < 350) {
                model_.start_placement(Model::Players::P2);
            }
        }
        // start button pressed
        if (position.x > 250 && position.x < 400) {
            if (position.y > 390 && position.y < 420) {
                model_.start_game();
            }
        }

    } else if (!model_.check_active() && !model_.is_game_over() && model_
            .board_placement()) {
        // shuffle button is pressed
        if (position.x > 100 && position.x < 250) {
            if (position.y > 500 && position.y < 580) {
                model_.shuffle_board();
            }
        }
        // done button is pressed
        if (position.x > 450 && position.x < 600) {
            if (position.y > 500 && position.y < 580) {
                model_.stop_placement();
            }
        }

    } else if (model_.check_active() && !model_.is_game_over() &&
               !model_.board_placement()) {

        ge211::Posn<int> board_pos = view_.screen_to_board(position);
        std::cout << board_pos << "\n";


        // for(std::vector<bool> vect : return_grid)
        // {
        //     for(bool tile : vect)
        //     {
        //         std::cout << tile << "\n";
        //     }
        }
        // for (int i = 0; i < 15; i++) {
        //     for (int j = 0; j < 8; j++) {
        //         Position start = {110, 40};
        //         start.x = start.x + (i * 35);
        //         start.y = start.y + (j * 35);
        //         if (position.x >= start.x && position.y <= start.x + 25) {
        //             if (position.y >= start.y && position.y <= start.y + 25) {
        //                 //
        //                 // // Board::Grid_vector board_grid =std::vector<std::vector<bool>>(15,std::vector<bool>(8, false));
        //                 // // board_grid[i][j] = (start.x, start.y);
        //                 // std::cout << "hey" << "\n" ;
        //
        //             }
        //         }
        //     }
        // }
    }








    // Model::Players player = Model::get_turn();
    // if(player == Model::Players::P2)
    // {
    //     ge211::geometry::Dims<int> x_dims( 490, 110);
    //     ge211::geometry::Dims<int> y_dims(280, 40);
    //     if(position.x <= x_dims.width && position.x >= x_dims.height
    //     && position.y >= y_dims.height && position.y <= y_dims.width)
    //
    //     {
    //         Board p1_board = model_.get_player_board(Model::Players::P1);
    //         Board::Grid_vector grid = p1_board.get_grid();
    //         Dimensions start = {110, 40};
    //
    //         Board::Grid_vector position_grid{};
    //
    //         for (int i = 0; i < 15; i++)
    //         {
    //             for (int j = 0; j < 8; j++)
    //             {
    //              position_grid[i][j] = {(i * (start.width + 35)), (j*
    //              (start.height + 35))};
    //             }
    //         }
    //     }
    //
    //     }
    //
    // if(player == Model::Players::P1)
    // {
    //     ge211::geometry::Dims<int> x_dims( 490, 110);
    //     ge211::geometry::Dims<int> y_dims(490, 680);
    //     if(position.x >= x_dims.height && position.x <= x_dims.width
    //     && position.y >= y_dims.width && position.y <= y_dims.height)
    //     {
    //
    //     }
    // }

    // if (Model::Players::P1) {
    //get player one's board and draw it to get posns
    // for the num colums = 15
    // for the num rows = 8
    // Position start = {110, 135};
    // if position.x > start.x && position.x < start.x + 25)
    // if position.y > start.y && position.y < start.y + 25)
    // start.x = start.x +

    //;







    // if (position.x > 250 && position.x < 400){
    //     if (position.y > 250 && position.y < 280){
    //         model_.player1_button = true;
    //         model_.player2_button = false;
    //         model_.start_game = false;
    //     }
    // }
    //
    // if (position.x > 250 && position.x < 400){
    //     if (position.y > 320 && position.y < 350){
    //         model_.player1_button = false;
    //         model_.player2_button = true;
    //         model_.start_game = false;
    //     }
    // }
    //
    // if (position.x > 250 && position.x < 400){
    //     if (position.y > 390 && position.y < 420){
    //         model_.player1_button = false;
    //         model_.player2_button = false;
    //         model_.start_game = true;
    //     }
    // }

    // if (position.x > 100 && position.x < 250){
    //     if (position.y > 500 && position.y < 580){
    //         model_.done_button = false;
    //         model_.shuffle_button = true;
    //     }
    // }
    //
    // if (position.x > 450 && position.x < 600){
    //     if (position.y > 500 && position.y < 580){
    //         model_.done_button = true;
    //         model_.shuffle_button = false;
    //     }
    // }
