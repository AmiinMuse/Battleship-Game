#pragma once

#include <ge211.hxx>
#include <vector>
#include <map>

class Ship
{
public:
    using Dimensions = ge211::geometry::Dims<int>;

    Ship(Dimensions dims);

    Dimensions get_dims();


private:
    const ge211::geometry::Dims<int> dims;

};