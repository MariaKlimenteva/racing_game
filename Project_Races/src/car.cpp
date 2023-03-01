#include <iostream>

#include "car.h"


car_t::car_t()
{
    color_ = 0;
    x_ = NAN;
    y_ = NAN;
    direction_ = NAN;
    speed_ = 0;
    max_speed_ = NAN;
    turning_radius_ = NAN;
    acceleration_ = NAN;
}
bool car_t::is_valid()
{
    if(x_ != x_)
        return false;
    if(y_ != y_)
        return false;
    if(direction_ != direction_)
        return false;
    if(speed_ != speed_)
        return false;
    if(max_speed_ != max_speed_)
        return false;
    if(turning_radius_ != turning_radius_)
        return false;
    if(acceleration_ != acceleration_)
        return false;
    return true;
}
void car_t::set_color(unsigned color)
{
    color_ = color;
}

void car_t::print()
{
    if(is_valid()) {
        std::cout << "Color: " << std::hex << color_ << std::endl;
        std::cout << "X = " << x_ << std::endl;
        std::cout << "Y = " << y_ << std::endl;
        std::cout << "Direction = " << direction_ << std::endl;
        std::cout << "Speed = " << speed_ << std::endl;
        std::cout << "Maximum speed = " << max_speed_ << std::endl;
        std::cout << "Turning radius = " << turning_radius_ << std::endl;
        std::cout << "Acceleration = " << acceleration_ << std::endl;
    }
}

void car_t::set_coordinates(double x, double y, double direction)
{
    x_ = x;
    y_ = y;
    direction_ = direction;
    speed_ = 0;
}

double car_t::get_x()
{
    return x_;
}

double car_t::get_y()
{
    return y_;
}
