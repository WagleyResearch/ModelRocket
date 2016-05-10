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
    //Rocket (mass, drag x, drag y, area x, area y, thrust 500, burn time length, flow rate);
    Rocket testProjectile(1500, .3, .7, 450, 7.8, 60000, 60, .5);
    World testWorld;
    double* out;
    out = thrust(testProjectile, testWorld, 75);
    printf("Meters traveled across: %f\nMeters traveled up: %f\nTime Taken: %f\n", out[0], out[1], out[2]);
    return 0;
}



