#pragma once

#include <ge211.hxx>
#include <map>


struct Game_config
{
    public:
        using Dimensions = ge211::geometry::Dims<int>;

        Game_config();


        const ge211::geometry::Dims<int> screen_dims;

        const Dimensions brick_dims ;
        const Dimensions grid_spacing;
        const Dimensions margins;
        const Dimensions button_dims;

        std::vector<Dimensions> ship_types;
};

