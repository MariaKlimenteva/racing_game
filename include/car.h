#ifndef CAR_H
#define CAR_H

#include <SDL.h>
#include "game.h"
#include "map.h"

#define ACCURACY 0.00001

#define DEFAULT_X 10
#define DEFAULT_Y 10
#define DEFAULT_DIRECTION M_PI

bool is_zero(double var);
bool is_equal(double var1, double var2);
int sign (double var);

class coordinates_t {
    private:
        double x_;
        double y_;
        double direction_;
    public:
        coordinates_t();
        coordinates_t(double x, double y, double direction);
        bool is_valid();
        void print();
        void qprint();
        double get_x();
        double get_y();
        double get_direction();
        void set_x(double x);
        void set_y(double y);
        void set_direction(double direction);
        void change_x(double dx);
        void change_y(double dy);
        void change_direction(double ddirection);
        void set_coordinates(double x, double y, double direction);
};


class car_t {
    private:
        unsigned color_;
        coordinates_t coordinates_;
        double speed_;
        double max_speed_;
        double turning_radius_;
        double acceleration_;
    /*
        FORWARD
        BACKWARD
        LEFT
        RIGHT
        BREAKS
    */
        Uint8 buttons[5];
        bool flags[5];

        int timer_;
        

    public:
        car_t();
        car_t(unsigned color, double max_speed, double turning_radius, double acceleration);
        car_t(unsigned color, double x, double y, double direction, double max_speed, double turning_radius, double acceleration);
        void init(unsigned color, double x, double y, double direction, double max_speed, double turning_radius, double acceleration);
        void init(unsigned color, double max_speed, double turning_radius, double acceleration);
        bool is_valid();
        void set_color(unsigned color);
        void set_coordinates(double x, double y, double direction);
        void set_butons(Uint8 forward, Uint8 backward, Uint8 left, Uint8 right, Uint8 breaks);
        coordinates_t get_coordinates();
        void print();
        void move(Map& GameMap, int id);
};

#endif//CAR_H