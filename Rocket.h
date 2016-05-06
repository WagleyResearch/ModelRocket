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
    Rocket(double m, double c, double a, double t, double b);
    double getMass();
    double getDrag();
    double getArea();
    double getThrust();
    double getBurn();

private:
    double mass, coef, area, thrust, burn;
};

#endif	/* ROCKET_H */

