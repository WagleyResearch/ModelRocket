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
    double t = 0;
    double tInc = .01;
    double vs = 10;
    double va = 13;
    double vx = vs * cos(va);
    double vy = vs * sin(va);
    double fnety, fnetx, fnets, fneta, vs2, va2, vx2, vy2, distx, rs, ra, rx, ry;
    distx = 0;
    double disty = 400;
    double a = rs / m;
    while (true) {
        fnety = vy - m * g;
        fnetx = vx;
        fneta = atan(fnety / fnetx) * 180 / PI;
        fnets = sqrt((fnetx * fnetx) + (fnety * fnety));
        va2 = atan(vy / vx) * 180 / PI;
        vs2 = sqrt((vx * vx) + (vy * vy));
        rs = c * d * vs2 * vs2 / 2;
        ra = va2 + 180;
        rx = rs * cos(ra * PI / 180);
        ry = rs * sin(ra * PI / 180);
        vx2 = vx - rx;
        vy2 = vy - ry - (m * g);
        disty += ((vy2*vy2) - (vy*vy)) / 2*(ry / m);
        distx += ((vx2*vx2) - (vx*vx)) / 2*(rx / m);
        a = rs / m;
        if (disty < 0) {
            break;
        }
        vx = vx2;
        vy = vy2;
        t = t + tInc;

    }
    return distx;
}

/*
 * 
 */
int main(int argc, char** argv) {
    Rocket testRocket(1000, .01, 4, 500, 10);
    World testWorld(1.223, 9.8);
    printf("Meters traveled: %f\n", coast(testRocket, testWorld));
    return 0;
}



