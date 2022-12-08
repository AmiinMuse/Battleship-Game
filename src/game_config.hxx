#pragma once

#include <ge211.hxx>
#include <map>


struct Game_config
{
    public:
        using Dimensions = ge211::Dims<int>;
        using Position = ge211::Posn<int>;

        Game_config();


        const ge211::geometry::Dims<int> screen_dims;

        const Dimensions brick_dims ;
        const Dimensions grid_spacing;
        const Dimensions button_dims;

        const Position P1_board_pos;
        const Position P2_board_pos;

        std::vector<Dimensions> ship_types;
};

