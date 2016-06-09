/* 
 * File:   Projectile.h
 * Author: student
 *
 * Created on May 6, 2016, 3:49 PM
 */

#ifndef PROJECTILE_H
#define PROJECTILE_H

class Projectile {
public:
public:
    Projectile(double m, double cx, double cy, double ax, double ay);
    double getMass();
    double getDragX();
    double getDragY();
    double getAreaX();
    double getAreaY();
    double getDistX();
    double getDistY();
    void setDistY(double dist);
    void setDistX(double dist);
    void setMass(double mass);
    /* static void openGraph();
    static void graphPath();
    static void closeGraph(); */

private:
    double mass, coefx, coefy, areax, areay, distx, disty;
};

#endif /* PROJECTILE_H */

