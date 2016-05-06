/* 
 * File:   Rocket.h
 * Author: student
 *
 * Created on May 5, 2016, 11:10 AM
 */
#include "Projectile.h"

#ifndef ROCKET_H
#define	ROCKET_H

class Rocket : public Projectile{
public:
    typedef Projectile super;
    Rocket(double m, double cx, double cy, double ax, double ay, double t, double b);
    double getThrust();
    double getBurn();

private:
    double thrust, burn;
};

#endif	/* ROCKET_H */

