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
    double cx = r.getDragX();
    double cy = r.getDragY();
    double Ax = r.getAreaX();
    double Ay = r.getAreaY();
    double d = b.getDensity();
    double g = b.getGravity();
    double Vx = V * cos(Vt * PI / 180);
    double Vy = V * sin(Vt * PI / 180);
    double Fdx, Fdy, ax, ay, Vx2, Vy2, Dx, Dy;
    double distx = 0;
    double disty = h;
    double t = 0;
    double tstep = .000001;

    while (disty >= 0) {
        Vt = atan(Vy / Vx) * 180 / PI;
        Dx = (cx * d * Ax * Vx * Vx) / 2;
        Dy = (cy * d * Ay * Vy * Vy) / 2;
        ax = -Dx / m;
        if ((Vt + 180) >= 180) {
            ay = -((Dy / m) + 9.8);
        } else if ((Vt + 180) < 180) {
            ay = ((Dy / m) - 9.8);
        }
        Vy2 = Vy + ay * tstep;
        Vx2 = Vx + ax * tstep;
        disty += Vy * tstep;
        distx += Vx * tstep;
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
    //Rocket (mass, drag x, drag y, area x, area y, thrust 500, burn time length);
    Rocket testRocket(50, .5, .5, .13, .13, 500, 10);
    World testWorld;
    printf("Meters traveled: %f\n", coast(testRocket, testWorld, 60, 10, 0));
    return 0;
}



