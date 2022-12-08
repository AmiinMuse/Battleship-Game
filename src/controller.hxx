#pragma once

#include "model.hxx"
#include "view.hxx"
#include "game_config.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    using Dimensions = ge211::geometry::Dims<int>;
    using Position = ge211::Posn<int>;

    std::string initial_window_title() const override;

    void on_mouse_down(ge211::Mouse_button m, ge211::Posn<int> position)
    override;


    Controller();

protected:
    void draw(ge211::Sprite_set& set) override;
    Dimensions initial_window_dimensions() const override;



private:
    Model model_;
    View view_;
    Game_config config_;
};