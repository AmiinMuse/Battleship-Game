#include "ship.hxx"

Ship::Ship(ge211::geometry::Dims<int> dims)
        : dims(dims)
{}

ge211::geometry::Dims<int>
Ship::get_dims()
{
    return dims;
}

std::vector<std::vector<int>>
Ship::get_locations()
{
    return locations;
}

void
Ship::set_locations(std::vector<std::vector<int>> new_locations)
{
    locations = new_locations;
}