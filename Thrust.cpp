/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Thrust.h"

double * coast(Projectile r, World b, double V /*Velocity*/,
        double Vt /*Direction in Degrees */, double h /*height*/) {
                                                                 
    static double outCoast[3];
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
    outCoast[0] = distx;
    outCoast[1] = disty;
    outCoast[2] = t;

    return outCoast;
}
double * thrust(Rocket r, World b, double lt) {
    double outThrust[3];
    double *outC;
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
    outC = coast(r, b, sqrt((Vx * Vx) + (Vy * Vy)), atan((Vy / Vx) * 180 / PI), disty);
    outThrust[0] = distx + outC[0];
    outThrust[1] = disty + outC[1];
    outThrust[2] = t + outC[1];

    return outThrust;
}
