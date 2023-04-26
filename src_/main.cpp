#include <iostream>
#include <stdlib.h>

#include "car.h"

int main() {

    car_t car = car_t(0, 2, 2, 0.1);
    car.set_butons(SDLK_w, SDLK_s, SDLK_a, SDLK_d, SDLK_SPACE); 
    for(;1;){
        car.get_coordinates().print();
        car.move();
    }

    return 0;
}