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
    timer_ = 0;
}

car_t::car_t(unsigned color, double max_speed, double turning_radius, double acceleration)
{
    color_ = color;
    x_ = 0;
    y_ = 0;
    direction_ = 0;
    speed_ = 0;
    max_speed_ = max_speed;
    turning_radius_ = turning_radius;
    acceleration_ = acceleration;
    timer_ = 0;
}

car_t::car_t(unsigned color, double x, double y, double direction, double max_speed, double turning_radius, double acceleration)
{
    color_ = color;
    x_ = x;
    y_ = y;
    direction_ = direction;
    speed_ = 0;
    max_speed_ = max_speed;
    turning_radius_ = turning_radius;
    acceleration_ = acceleration;
    timer_ = 0;
}


void car_t::init(unsigned color, double x, double y, double direction, double max_speed, double turning_radius, double acceleration)
{
    color_ = color;
    x_ = x;
    y_ = y;
    direction_ = direction;
    speed_ = 0;
    max_speed_ = max_speed;
    turning_radius_ = turning_radius;
    acceleration_ = acceleration;
    timer_ = 0;
}


void car_t::init(unsigned color, double max_speed, double turning_radius, double acceleration)
{
    this->init(color, 0, 0, 0, max_speed, turning_radius, acceleration);
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

void car_t::move()
{
    if (timer_ == 0)
        timer_ = clock();
    else {
        double sp = speed_;
        double dir = direction_;
        int prtime = timer_;
        timer_ = clock();
        double dt = (timer_ - prtime) / CLOCKS_PER_SEC;

        if (/*&& Break*/ && !(is_zero(speed_))) {
            if (speed_ > 0 ) {
                speed_ -= acceleration_ * dt;
                if(speed_ < 0)
                    speed_ = 0; 
            }
            else if (speed_ < 0) 
                speed_ += acceleration_ * dt;
                if(speed_ > 0)
                    speed_ = 0;
        } 
        else if(/*Forward*/ && !(is_equal(speed_, max_speed_))) {
            speed_ += acceleration_ * dt;
            if(sp < 0 && speed_ > 0)
                speed_ = 0;
            else if(speed_ > max_speed_)
                speed_ = max_speed_;
        }
        else if(/*Backward*/ && !(is_equal(speed_, -max_speed_))) {
            speed_ -= acceleration_ * dt;
            if(sp > 0 && speed_ < 0)
                speed_ = 0;
            else if(speed_ < -max_speed_)
                speed_ = -max_speed_;
        }

        if((/*Left || Right*/) && !(/*Left && Right*/)) {
            int turning_flag;
            double radius = sp * sp / acceleration_;
            if(radius < turning_radius_)
                radius = turning_radius_;
            if(/*Right*/)
                turning_flag = 1;
            else
                turning_flag = -1;
            
            direction_ += (turning_flag * (sp + speed_) / 2) / radius * dt;
        
        }
        
        sp = (sp + speed_) / 2;
        dir = (dir + direction_) / 2;

        
        if(std::abs(direction_) > M_PI)
            direction_ -= sign(direction_) * 2 * M_PI;

        x_ += std::sin(dir) * sp * dt;
        y_ += std::cos(dir) * sp * dt;
    }

}
