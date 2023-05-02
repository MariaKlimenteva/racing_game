#include <iostream>
#include <cstdlib>
#include <ctime>

#include "car.h"

int main() {

    int prtime1 = 0, prtime2 = 0, timer = 0;


    car_t car;
    car.init(0, 4, 4, 1);
    car.set_butons(SDLK_w, SDLK_s, SDLK_a, SDLK_d, SDLK_SPACE); 

    for(timer = clock(); 1; timer = clock()){


        if((timer - prtime2) > CLOCKS_PER_SEC / 2) {
            car.get_coordinates().qprint();
            prtime2 = timer;
        }
        if((timer - prtime1) > CLOCKS_PER_SEC/100) {
            car.move();
            prtime1 = timer;
        }
    }

    return 0;
}