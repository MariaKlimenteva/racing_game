#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


#include "car.h"

bool is_zero(double var)
{
    return std::abs(var) < ACCURACY;
}

bool is_equal(double var1, double var2)
{
        return is_zero(var1 - var2);
}

int sign(double var)
{
    if(var > 0)
        return 1;
    return -1;
}

coordinates_t::coordinates_t()
{
    x_ = NAN;
    y_ = NAN;
    direction_ = NAN;
}

coordinates_t::coordinates_t(double x, double y, double direction)
{
    x_ = x;
    y_ = y;
    direction_ = direction;
}

bool coordinates_t::is_valid()
{
    if(x_ != x_)
        return false;
    if(y_ != y_)
        return false;
    if(direction_ != direction_)
        return false;
    return true;
}

void coordinates_t::print()
{
    std::cout << "X = " << x_ << std::endl;
    std::cout << "Y = " << y_ << std::endl;
    std::cout << "Direction = " << direction_ << std::endl;
}

void coordinates_t::qprint()
{
    std::cout << "( " << x_ << " , " << y_ << " ) " << direction_ << std::endl;

}

double coordinates_t::get_x()
{
    return x_;
}

double coordinates_t::get_y()
{
    return y_;
}

double coordinates_t::get_direction()
{
    return direction_;
}

void coordinates_t::set_x(double x)
{
    x_ = x;
}

void coordinates_t::set_y(double y)
{
    y_ = y;
}

void coordinates_t::set_direction(double direction)
{
    direction_ = direction;
}

void coordinates_t::change_x(double dx)
{
    x_ += dx;
}

void coordinates_t::change_y(double dy)
{
    y_ += dy;
}

void coordinates_t::change_direction(double ddirection)
{
    direction_ += ddirection;
}

void coordinates_t::set_coordinates(double x, double y, double direction)
{
    x_ = x;
    y_ = y;
    direction_ = direction;
}

car_t::car_t()
{
    color_ = 0;
    coordinates_t();
    speed_ = 0;
    max_speed_ = NAN;
    turning_radius_ = NAN;
    acceleration_ = NAN;
    timer_ = 0;
}

car_t::car_t(unsigned color, double max_speed, double turning_radius, double acceleration)
{
    color_ = color;
    coordinates_t(DEFAULT_X, DEFAULT_Y, DEFAULT_DIRECTION);
    speed_ = 0;
    max_speed_ = max_speed;
    turning_radius_ = turning_radius;
    acceleration_ = acceleration;
    timer_ = 0;
}

car_t::car_t(unsigned color, double x, double y, double direction, double max_speed, double turning_radius, double acceleration)
{
    color_ = color;
    coordinates_t(x, y, direction);
    speed_ = 0;
    max_speed_ = max_speed;
    turning_radius_ = turning_radius;
    acceleration_ = acceleration;
    timer_ = 0;
}

void car_t::init(unsigned color, double x, double y, double direction, double max_speed, double turning_radius, double acceleration)
{
    color_ = color;
    set_coordinates(x, y, direction);
    speed_ = 0;
    max_speed_ = max_speed;
    turning_radius_ = turning_radius;
    acceleration_ = acceleration;
    timer_ = 0;
}

void car_t::init(unsigned color, double max_speed, double turning_radius, double acceleration)
{
    this->init(color, DEFAULT_X, DEFAULT_Y, DEFAULT_DIRECTION, max_speed, turning_radius, acceleration);
}

bool car_t::is_valid()
{
    if(speed_ != speed_)
        return false;
    if(max_speed_ != max_speed_)
        return false;
    if(turning_radius_ != turning_radius_)
        return false;
    if(acceleration_ != acceleration_)
        return false;
    return coordinates_.is_valid();
}

void car_t::set_color(unsigned color)
{
    color_ = color;
}

void car_t::print()
{
    if(is_valid()) {
        std::cout << "Color: " << std::hex << color_ << std::endl;
        std::cout << "Coordinates:" << std::endl;
        coordinates_.print();
        std::cout << "Speed = " << speed_ << std::endl;
        std::cout << "Maximum speed = " << max_speed_ << std::endl;
        std::cout << "Turning radius = " << turning_radius_ << std::endl;
        std::cout << "Acceleration = " << acceleration_ << std::endl;
    }
}

void car_t::set_coordinates(double x, double y, double direction)
{
    coordinates_.set_coordinates(x, y, direction);
}

void car_t::set_butons(Uint8 forward, Uint8 backward, Uint8 left, Uint8 right, Uint8 breaks)
{
    buttons[0] = forward; 
    buttons[1] = backward; 
    buttons[2] =  left;
    buttons[3] =  right;
    buttons[4] =  breaks;
}

coordinates_t car_t::get_coordinates()
{
    return coordinates_;
}

void car_t::move()
{
    if (timer_ == 0)
        timer_ = clock();
    else {
        double sp = speed_;
        double dir = coordinates_.get_direction();
        int prtime = timer_;
        timer_ = clock();
        double dt = ((double)timer_ - (double)prtime) / CLOCKS_PER_SEC;

        const Uint8 * keystate = SDL_GetKeyboardState(NULL);
        for (int i = 0; i < 5; i++) {
           flags[i] = keystate[buttons[i]];
        }
        //flags[1] = 1;
        //flags[3] = 1;


        if (flags[4] && !(is_zero(speed_))) {

            if (speed_ > 0 ) {
                speed_ -= acceleration_ * dt;
                if(speed_ < 0)
                    speed_ = 0; 
            }
            else if (speed_ < 0) {
                speed_ += acceleration_ * dt;
                if(speed_ > 0)
                    speed_ = 0;
            }
        } 
        else if(flags[0] && !(is_equal(speed_, max_speed_))) {
            speed_ += acceleration_ * dt;
            if(sp < 0 && speed_ > 0)
                speed_ = 0;
            else if(speed_ > max_speed_)
                speed_ = max_speed_;
        }
        else if(flags[1] && !(is_equal(speed_, -max_speed_))) {
            speed_ -= acceleration_ * dt;
            if(sp > 0 && speed_ < 0)
                speed_ = 0;
            else if(speed_ < -max_speed_)
                speed_ = -max_speed_;
        }

        if((flags[2] || flags[3]) && !(flags[2] && flags[3])) {

            int turning_flag;
            double radius = sp * sp / acceleration_;
            if(radius < turning_radius_)
                radius = turning_radius_;
            if(flags[3])
                turning_flag = 1;
            else
                turning_flag = -1;
            
            coordinates_.change_direction((turning_flag * (sp + speed_) / 2) / radius * dt);
        
        }

        sp = (sp + speed_) / 2;
        dir = (dir + coordinates_.get_direction()) / 2;

        
        if(std::abs(coordinates_.get_direction()) > M_PI)
            coordinates_.change_direction( -(sign(coordinates_.get_direction()) * 2 * M_PI) );

        coordinates_.change_x(std::sin(dir) * sp * dt);
        coordinates_.change_y( -(std::cos(dir) * sp * dt));
    }

}

