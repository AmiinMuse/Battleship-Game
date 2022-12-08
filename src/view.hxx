#pragma once

#include "model.hxx"

class View
{
public:
    using Position = ge211::Posn<int>;
    using Dimensions = ge211::Dims<int>;

    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    void start_screen (ge211::Sprite_set& set);

    void placement_screen (ge211::Sprite_set& set);

    void game_screen (ge211::Sprite_set& set);

    void game_over_screen (ge211::Sprite_set& set);

    // helper function that creates a board for each player
    void draw_board(Board board, Position start_pos, ge211::Sprite_set&
    set, bool reveal);


private:
    Model const& model_;

    ge211::Font sans30{"sans.ttf", 30};
    //start screen sprites
    ge211::Text_sprite player_1;
    ge211::Text_sprite player_2;
    ge211::Text_sprite start_sprite;

    //placing board sprites
    ge211::Text_sprite shuffle_sprite;
    ge211::Text_sprite done_button;

    // game screen
    ge211::Text_sprite game_player_1_button;
    ge211::Text_sprite game_player_2_button;

    //game over sprites
    ge211::Rectangle_sprite game_over_bg;
    ge211::Text_sprite game_over_sprite;
    ge211::Text_sprite winner_sprite;
    ge211::Text_sprite score_sprite;

    ge211::Rectangle_sprite const grid_sprite;
    ge211::Rectangle_sprite const fill_grid_sprite;
    ge211::Rectangle_sprite const button_sprite;
    ge211::Rectangle_sprite const grid_clicked;
    ge211::Rectangle_sprite const ship_clicked;



};