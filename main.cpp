/* 
 * File:   main.cpp
 * Author: student
 *
 * Created on May 5, 2016, 10:51 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "Projectile.h"
#include "Rocket.h"
#include "World.h"
#include "Thrust.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Rocket (mass, drag x, drag y, area x, area y, newtons of thrust , burn time , flow rate);
    Rocket rocket(1000, .3, .3, .25, .25, 20000, 60, 20);
    /*World ( density of air,  acceleration due to gravity) if this is left blank then it creates a world
        equivalent to earth. */
    World world;
    // Creates array to handle output, first value is distance traveled on  x, then dist on y, then seconds of travel.
    double* out;
    //runs thrust function passing it the rocket, the world it is in, and the angle of launch
    out = thrust(rocket, world, 45);
    printf("Meters traveled across: %f\nMeters traveled up: %f\nTime Taken: %f\n", out[0], out[1], out[2]);
    //plots in GNUPlot 
    plot();
    return 0;
}



