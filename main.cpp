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

#define PI 3.14159265
using namespace std;

double coast(Projectile r, World b, double V /*Velocity*/,
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
    return disty;

}

double thrust(Rocket r, World b, double lt) {
    double m = r.getMass();
    double cx = r.getDragX();
    double cy = r.getDragY();
    double Ax = r.getAreaX();
    double Ay = r.getAreaY();
    double d = b.getDensity();
    double g = b.getGravity();
    double Tx = r.getThrust() * cos(lt * PI / 180);
    double Ty = r.getThrust() * sin(lt * PI / 180);
    double Vx, Vy = 0;
    double Fdx, Fdy, ax, ay, Vx2, Vy2, Dx, Dy;
    double distx, disty = 0;
    double t = 0;
    double tstep = .000001;
    while (t <= r.getBurn()) {
        Vx = Vx + (Tx / m) * tstep;
        Vy = Vy + ((Ty + 9.8) / m) * tstep;
        Dx = (cx * d * Ax * Vx * Vx) / 2;
        Dy = (cy * d * Ay * Vy * Vy) / 2;
        Vx2 = Vx - (Dx / m) * tstep;
        Vy2 = Vy - (Dx / m) * tstep;
        distx += Vx2 * tstep;
        disty += Vy2 * tstep;
        Vx = Vx2;
        Vy = Vy2;
        t = t + tstep;
        r.setMass(m + r.getFlow() / tstep);
    }
    return disty + coast(r, b, sqrt((Vx * Vx) + (Vy * Vy)), atan(Vy / Vx) * 180 / PI, disty);
}
//This Function calculates how far an object will travel when thrust stops

/*
 * 
 */
int main(int argc, char** argv) {
    //Rocket (mass, drag x, drag y, area x, area y, thrust 500, burn time length, flow rate);
    Rocket testProjectile(6540000, .3, .7, 450, 7.8, 34020000, 1025, 213);
    World testWorld;
    printf("Meters traveled: %f\n", thrust(testProjectile, testWorld, 90));
    return 0;
}



