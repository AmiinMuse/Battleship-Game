#include "view.hxx"
#include <iostream>

View::View(Model const& model)
        : model_(model),
          game_over_bg({300, 300}, ge211::Color::black()),
          grid_sprite(model_.config_.brick_dims, ge211::Color::white()),
          fill_grid_sprite(model_.config_.brick_dims, ge211::Color::medium_green()),
          button_sprite(model_.config_.button_dims, ge211::Color::white()),
          grid_clicked(model_.config_.brick_dims, ge211::Color(14,135,204)),
          ship_clicked(model_.config_.brick_dims, ge211::Color::medium_red())
{ }


void
View::draw(ge211::Sprite_set& set)
{

    if (!model_.check_active() && !model_.is_game_over() && !model_.board_placement()){
        start_screen (set);
    } else if (!model_.check_active() && !model_.is_game_over() && model_.board_placement()){
        placement_screen(set);
    } else if (model_.check_active() && !model_.is_game_over() && !model_.board_placement()){
        game_screen(set);
    } else if (!model_.check_active() && model_.is_game_over() && !model_.board_placement()){
        game_screen(set);
        game_over_screen(set);
    }

}

void
View::draw_board(Board board, Position start_pos, ge211::Sprite_set& set,
                 bool reveal) {
    auto grid = board.get_grid();
    // i -> col
    // j -> row
    for (unsigned int i = 0; i < grid.size(); i++) {
        for (unsigned int j = 0; j < grid[i].size(); j++) {
            Game_config config = model_.config_;
            Position place_pos = {start_pos.x,start_pos.y};

            place_pos.x += i * (config.brick_dims.width + config
                    .grid_spacing.width);

            place_pos.y += j * (config.brick_dims.height + config
                    .grid_spacing.height);

            if (reveal) {
                if (grid[i][j][2]) {
                    set.add_sprite(fill_grid_sprite, {place_pos.x , place_pos.y});
                } else {
                    set.add_sprite(grid_sprite, {place_pos.x , place_pos.y});
                }
            } else {
                if (grid[i][j][0] && grid[i][j][1]) {
                    set.add_sprite(ship_clicked, {place_pos.x, place_pos.y});
                } else if (grid[i][j][0]) {
                    set.add_sprite(grid_clicked, {place_pos.x , place_pos.y});
                } else {
                    set.add_sprite(grid_sprite, {place_pos.x , place_pos.y});
                }
            }
        }
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
View::game_screen(ge211::Sprite_set& set)
{
    draw_board(model_.get_player_board(Model::Players::P1), {110, 40},
               set, false);
    draw_board(model_.get_player_board(Model::Players::P2), {110, 400},
               set, false);

    ge211::Text_sprite::Builder game_player_1(sans30);
    game_player_1.color(ge211::Color::medium_green()) << "Player-1";
    game_player_1_button.reconfigure(game_player_1);
    set.add_sprite(button_sprite, {550, 0});
    set.add_sprite(game_player_1_button, {552, -10}, 0);

    ge211::Text_sprite::Builder game_player_2(sans30);
    game_player_2.color(ge211::Color::medium_green()) << "Player-2";
    game_player_2_button.reconfigure(game_player_2);
    set.add_sprite(button_sprite, {550, 350});
    set.add_sprite(game_player_2_button, {552, 340}, 350);
}

void
View::game_over_screen(ge211::Sprite_set& set) {

    set.add_sprite(game_over_bg, {200, 200}, 1000);

    ge211::Text_sprite::Builder game_over(sans30);
    game_over.color(ge211::Color::medium_green()) << "Game Over";
    game_over_sprite.reconfigure(game_over);
    set.add_sprite(game_over_sprite, {270, 230}, 1001);

    ge211::Text_sprite::Builder winner(sans30);
    winner.color(ge211::Color::medium_green()) << "Winner: " << model_
    .get_winner();
    winner_sprite.reconfigure(winner);
    set.add_sprite(winner_sprite, {250, 290}, 1001);


    ge211::Text_sprite::Builder score(sans30);
    score.color(ge211::Color::medium_green()) << "Score: " << model_
    .get_winner_score();
    score_sprite.reconfigure(score);
    set.add_sprite(score_sprite, {250, 340}, 1001);
}
