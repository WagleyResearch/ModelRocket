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

double Launch(Rocket a, World b, int phi, int c /*if c is 0 return the time in air, 
                                                 * if 1 return x distance, if 2 return y distance.*/) {
    double vfx, vfy, vix, viy, fax, fay, fnx, fny, distx, disty;
    double t = .001;
    bool loop = true;
    int loopCounter = 0;
    fnx = (a.getThrust() * cos(phi * PI / 180)) - (a.getMass() * b.getGravity());
    fny = (a.getThrust() * sin(phi * PI / 180));
    while (loop) {

        vfy = viy + ((a.getDrag() * b.getDensity() * a.getArea() * t) / 2 * a.getMass());
        vfx = vix + ((a.getDrag() * b.getDensity() * a.getArea() * t) / 2 * a.getMass());
        disty = vfy + -9.8 * t*t;
        distx = vfx*t;
        if (loopCounter < a.getBurn()) {
            fax = a.getDrag() * b.getDensity() * a.getArea() * vfx / 2;
            fay = a.getDrag() * b.getDensity() * a.getArea() * vfy / 2;
            fnx += fax;
            fny += fay;
        }
        if (disty <= 0) {
            break;
        }
        t++;
    }
    if (c == 1) {
        return distx;
    } else if (c == 0) {
        return t;
    } else if (c == 2) {
        return disty;
    }
    return t;
}

double coast(Rocket r, World b) {
    double m = r.getMass();
    double c = r.getDrag();
    double A = r.getArea();
    double d = b.getDensity();
    double g = b.getGravity();
    double Vx = 100 * cos(45 * PI / 180);
    double Vy = 100 * sin(45 * PI / 180) - m * g;
    double V, Vt, Fdx, Fdy, ax, ay, Vx2, Vy2;
    double distx = 0;
    double disty = 400;
    double t = 0;
    double tstep = .01;
    while(true){
        V = sqrt((Vx*Vx) + (Vy*Vy));
        Vt = atan(Vy / Vx) * 180 / PI;
        Fdx = (c * d * A * V * V) * cos((Vt + 180) * PI / 180);
        Fdy = (c * d * A * V * V) * sin((Vt + 180) * PI / 180);
        ax = Fdx / m;
        ay = Fdy / m;
        Vy2 = Vy + ay * tstep;
        Vx2 = Vx + ax * tstep;
        disty += (Vy2 + Vy) / 2 * tstep;
        distx += (Vx2 + Vx) / 2 * tstep;
        printf(" time %f\n Vx %f\n Vx2 %f\n", t, Vx, Vx2 );
        Vy = Vy2 - m * g;
        Vx = Vx2;
        
        if (disty < 0){
            break;
        }
        t += tstep;
        
        
    }
    return distx;
 
}

/*
 * 
 */
int main(int argc, char** argv) {
    Rocket testRocket(1, .05, 4, 500, 10);
    World testWorld(1.223, 9.8);
    printf("Meters traveled: %f\n", coast(testRocket, testWorld));
    return 0;
}



