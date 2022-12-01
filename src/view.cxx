#include "view.hxx"
#include <iostream>

View::View(Model const& model)
        : model_(model),
          grid_sprite(model_.config_.brick_dims, ge211::Color::white()),
          fill_grid_sprite(model_.config_.brick_dims, ge211::Color::medium_green()),
          button_sprite(model_.config_.button_dims, ge211::Color::white())
{ }


void
View::draw(ge211::Sprite_set& set)
{


    // if (!model_.check_active() && !model_.is_game_over() && !model_.board_placement()){
    //     if (!model_.player1_button && !model_.player2_button && !model_.start_game){
    //         start_screen (set);
    //     } else {
    //         if (model_.player1_button){
    //             if (!model_.done_button){
    //                 placement_screen({300, 300}, set);
    //             } else {
    //                 start_screen (set);
    //             }
    //
    //         } else if (model_.player2_button){
    //             if (!model_.done_button){
    //                 placement_screen({300, 300}, set);
    //             } else {
    //                 start_screen (set);
    //             }
    //
    //         } else if (model_.start_game){
    //             draw_board(model_.get_player_board(Model::Players::P1), {110, 40}, set);
    //             draw_board(model_.get_player_board(Model::Players::P1), {110, 400}, set);
    //         }
    //
    //     }
    // }



    if (!model_.check_active() && !model_.is_game_over() && !model_.board_placement()){
        start_screen (set);

    } else if (!model_.check_active() && !model_.is_game_over() && model_
            .board_placement()){
        placement_screen(set);
    } else if (model_.check_active() && !model_.is_game_over() && !model_.board_placement()){
        draw_board(model_.get_player_board(Model::Players::P1), {110, 40},
                   set, false);
        draw_board(model_.get_player_board(Model::Players::P2), {110, 400},
                   set, false);
    } else if (!model_.check_active() && model_.is_game_over() && !model_
            .board_placement()){
        // gameover_screen(set);
    }

}

void
View::start_screen (ge211::Sprite_set& set){

    // player 1
    ge211::Text_sprite::Builder name_builder(sans30);
    name_builder.color(ge211::Color::medium_green()) << "Player1";
    player_1.reconfigure(name_builder);
    set.add_sprite(button_sprite, {250, 250});
    set.add_sprite(player_1, {270, 238}, 300);


    //player 2
    ge211::Text_sprite::Builder score_builder(sans30);
    score_builder.color(ge211::Color::medium_green()) << "Player2";
    player_2.reconfigure(score_builder);
    set.add_sprite(button_sprite, {250, 320});
    set.add_sprite(player_2, {270, 310}, 300);

    // start
    ge211::Text_sprite::Builder hey_builder(sans30);
    hey_builder.color(ge211::Color::medium_green()) << "Start";
    start_sprite.reconfigure(hey_builder);
    set.add_sprite(button_sprite, {250, 390});
    set.add_sprite(start_sprite, {270, 380}, 300);

}

void
View::placement_screen(ge211::Sprite_set& set) {
    draw_board(model_.get_player_board(model_.board_placement_player()),
               {110, 40}, set, true);

    ge211::Text_sprite::Builder shuffle_(sans30);
    shuffle_.color(ge211::Color::medium_green()) << "Shuffle";
    shuffle_sprite.reconfigure(shuffle_);
    set.add_sprite(button_sprite, {100, 500});
    set.add_sprite(shuffle_sprite, {110, 490}, 300);

    ge211::Text_sprite::Builder done(sans30);
    done.color(ge211::Color::medium_green()) << "Done";
    done_button.reconfigure(done);
    set.add_sprite(button_sprite, {450, 500});
    set.add_sprite(done_button, {460, 490}, 300);
}

void
View::gameover_screen (Position pos, ge211::Sprite_set& set){

    ge211::Text_sprite::Builder game_over(sans30);
    game_over.color(ge211::Color::medium_green()) << "Game Over";
    gameover_sprite.reconfigure(game_over);
    set.add_sprite(grid_sprite, {300, 500});


    ge211::Text_sprite::Builder winner(sans30);
    winner.color(ge211::Color::medium_green()) << "Winner";
    winner_sprite.reconfigure(game_over);
    set.add_sprite(grid_sprite, {300, 700});


    ge211::Text_sprite::Builder score(sans30);
    winner.color(ge211::Color::medium_green()) << "Score";
    score_sprite.reconfigure(game_over);
    set.add_sprite(grid_sprite, {300, 700});
}



void
View::draw_board(Board board, Position start_pos, ge211::Sprite_set& set,
                 bool reveal)
{
    auto grid = board.get_grid();
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            Game_config config = model_.config_;
            Position place_pos = {0,0};

            place_pos.x = start_pos.x +  (i * (config.grid_spacing.width +
                    config.brick_dims.width));
            place_pos.y = start_pos.y + (j * (config.grid_spacing.height +
                                              config.brick_dims.height));

            if (reveal && grid[i][j]) {
                set.add_sprite(fill_grid_sprite, {place_pos.x , place_pos.y});
            } else {
                set.add_sprite(grid_sprite, {place_pos.x , place_pos.y});
            }
        }
    }

}

ge211::Posn<int> View::screen_to_board(Position pos)
{
    ge211::Posn<int> board_pos{(pos.x - 110) / 35, (pos.y - 40) /35};
    return board_pos;

    // for (int i = 0; i < 15; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         Position start = {110, 40};
    //         start.x = start.x + (i * 35);
    //         start.y = start.y + (j * 35);
    //         if (position.x >= start.x && position.y <= start.x + 25)
    //         {
    //             if (position.y >= start.y && position.y <= start.y + 25)
    //             {
    //                 i][i] = start.x;
    //                 [i][j] = start.y;
    //                 //std::cout << true;
    //             }
    //         }
    //     }
    // }
    // return ;
}

// void
// View::change_color()
// {
//     ge211::Rectangle_sprite({25, 25}, ge211::Color::black());
// }

// Board const
// View::screen_to_board(View::Position pos, Model::Players players) const
// {
//     if(Model::Players::P1)
//     {
//        model_.get_player_board(Model::P2);
//     }
//     return {pos.x / model_.config_.brick_dims.width , pos.y / model_
//     .config_.brick_dims.height};
// }


// void Controller::on_mouse_down(ge211::Mouse_button m, ge211::Posn<int> position)
// {
//
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             std::cout << model_.square_at(i, j) << " ";
//         }
//     }
//
//     View::Position board_pos = view_.screen_to_board(position);
//
//     // send an update to model to update the squares array at active square
//     model_.play_move(board_pos.x, board_pos.y);
// }




