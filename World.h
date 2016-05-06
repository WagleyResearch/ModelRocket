/* 
 * File:   World.h
 * Author: student
 *
 * Created on May 5, 2016, 11:24 AM
 */

#ifndef WORLD_H
#define	WORLD_H

class World {
public:
    World(double d, double g);
    double getDensity();
    double getGravity();
private:
    double dens, g;
};

#endif	/* WORLD_H */

