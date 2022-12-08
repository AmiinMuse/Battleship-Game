#include "ship.hxx"

Ship::Ship(ge211::geometry::Dims<int> dims)
        : dims(dims)
{}

ge211::geometry::Dims<int>
Ship::get_dims()
{
    return dims;
}
