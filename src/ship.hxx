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


    std::vector<std::vector<int>> get_locations();

    void set_locations(std::vector<std::vector<int>> new_locations);

private:
    const ge211::geometry::Dims<int> dims;
    std::vector<std::vector<int>> locations;

    //bool sunk = false;
};