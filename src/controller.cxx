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
            model_.grid_clicked(position);
            if (position.x > 650 && position.y > 650) {
                model_.force_game_over(Model::Players::P1);
            }
    }

}