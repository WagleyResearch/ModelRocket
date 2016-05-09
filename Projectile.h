/* 
 * File:   Projectile.h
 * Author: student
 *
 * Created on May 6, 2016, 3:49 PM
 */

#ifndef PROJECTILE_H
#define	PROJECTILE_H

class Projectile {
public:
   public:
    Projectile(double m, double cx, double cy, double ax, double ay);
    double getMass();
    double getDragX();
    double getDragY();
    double getAreaX();
    double getAreaY();
    void setMass(double mass);

private:
    double mass, coefx, coefy, areax, areay;
};

#endif	/* PROJECTILE_H */

