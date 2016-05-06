/* 
 * File:   Rocket.h
 * Author: student
 *
 * Created on May 5, 2016, 11:10 AM
 */

#ifndef ROCKET_H
#define	ROCKET_H

class Rocket {
public:
    Rocket(double m, double cx, double cy, double ax, double ay, double t, double b);
    double getMass();
    double getDragX();
    double getDragY();
    double getAreaX();
    double getAreaY();
    double getThrust();
    double getBurn();

private:
    double mass, coefx, coefy, areax, areay, thrust, burn;
};

#endif	/* ROCKET_H */

