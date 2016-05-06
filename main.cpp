/* 
 * File:   main.cpp
 * Author: student
 *
 * Created on May 5, 2016, 10:51 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "Rocket.h"
#include "World.h"

#define PI 3.14159265
using namespace std;

//This Function calculates how far an object will travel when thrust stops

double coast(Rocket r, World b, double V /*Velocity*/,
        double Vt /*Direction in Degrees */, double h /*height*/) {
    double m = r.getMass();
    double c = r.getDrag();
    double A = r.getArea();
    double d = b.getDensity();
    double g = b.getGravity();
    double Vx = V * cos(Vt * PI / 180);
    double Vy = V * sin(Vt * PI / 180);
    double Fdx, Fdy, ax, ay, Vx2, Vy2, Dx, Dy;
    double distx = 0;
    double disty = h;
    double t = 0;
    double tstep = .01;

    while (disty >= 0) {
        /* V = sqrt((Vx * Vx) + (Vy * Vy));
         Vt = atan(Vy / Vx) * 180 / PI; 
         Fdx = (c * d * A * V * V) * cos((Vt + 180) * PI / 180);
         Fdy = (c * d * A * V * V) * sin((Vt + 180) * PI / 180) - m * g; */
        Dx = (c * d * A * Vx * Vx) / 2;
        Dy = (c * d * A * Vy * Vy) / 2;
        ax = Dx / m;
        ay = ((Dy / m) + 9.8);
        Vy2 = Vy - ay * tstep;
        Vx2 = Vx - ax * tstep;
        disty += Vy * tstep;
        distx += Vx * tstep;
        printf("T: %f\n Vx %f\n Vy %f\n V %f\n", t, Vx, Vy, sqrt((Vx * Vx) + (Vy * Vy)));
        t += tstep;
        Vx = Vx2;
        Vy = Vy2;


    }
    return distx;

}

/*
 * 
 */
int main(int argc, char** argv) {
    //Rocket (Mass, Drag Coeffiecent, Cross Sectional Area, Thrust, Burn Time )
    Rocket testRocket(1, .47, .1, 500, 10);
    World testWorld(1.22, 9.8);
    printf("Meters traveled: %f\n", coast(testRocket, testWorld, 100, 13, 400));
    return 0;
}



