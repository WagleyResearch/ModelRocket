/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Thrust.h"

//Calculates how far a projectile will travel without thrust

double * coast(Projectile r, World b, double V /*Velocity*/,
        double Vt /*Direction in Degrees */) {
    FILE *data = fopen("data.dat", "a");
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
    double t = 0;
    double tstep = .01;

    while (r.getDistY() >= 0) {
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
        r.setDistY(r.getDistY() + (Vy * tstep));
        r.setDistX(r.getDistX() + (Vx * tstep));
        fprintf(data, "%f %f\n", r.getDistX(), r.getDistY());
        t += tstep;
        Vx = Vx2;
        Vy = Vy2;

    }
    fflush(data);
    fclose(data);
    outCoast[0] = r.getDistX();
    outCoast[1] = r.getDistY();
    outCoast[2] = t;

    return outCoast;
}

//Calculates how far a rocket will travel under thrust

double * thrust(Rocket r, World b, double lt) {
    FILE *data = fopen("data.dat", "w");
    
    int pointCount = 0;
    double outThrust[3];
    double *outC;
    double m = r.getMass();
    double cx = r.getDragX();
    double cy = r.getDragY();
    double Ax = r.getAreaX();
    double Ay = r.getAreaY();
    double d = b.getDensity();
    double g = b.getGravity();
    double T = r.getThrust();
    double Tx = T * cos(lt * PI / 180);
    double Ty = T * sin(lt * PI / 180);
    double Vx = 0;
    double Vy = 0;
    double Fdx, Fdy, ax, ay, Vx2, Vy2, Dx, Dy;
    double distx = 0;
    double disty = 0;
    double t = 0;
    double tstep = .01;
    while (t <= r.getBurn()) {
        Vx = Vx + ((Tx / m) * tstep);
        Vy = Vy + ((Ty + 9.8) / m) * tstep;
        Dx = (cx * d * Ax * Vx * Vx) / 2;
        Dy = (cy * d * Ay * Vy * Vy) / 2;
        Vx2 = Vx - (Dx / m) * tstep;
        Vy2 = Vy - (Dx / m) * tstep;
        r.setDistX(r.getDistX() + (Vx2 * tstep));
        r.setDistY(r.getDistY() + (Vx2 * tstep));
        Vx = Vx2;
        Vy = Vy2;
        t = t + tstep;

        //r.setMass(m + r.getFlow() / tstep);
        fprintf(data, "%f %f\n", r.getDistX(), r.getDistY());


        pointCount++;
    }
    fflush(data);
    fclose(data);
    outC = coast(r, b, sqrt((Vx * Vx) + (Vy * Vy)), atan((Vy / Vx)) * 180 / PI);
    outThrust[0] = r.getDistX();
    outThrust[1] = r.getDistY();
    outThrust[2] = t + outC[1];

    return outThrust;


}
void plot(){
    system("/usr/local/bin/gnuplot -persist -e \"set terminal x11; plot 'data.dat' smooth bezier \" " );
    printf("To End Program Hit Enter\n");
    std::cin.ignore();
}
