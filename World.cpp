/* 
 * File:   World.cpp
 * Author: student
 * 
 * Created on May 5, 2016, 11:24 AM
 */

#include "World.h"

World::World(double d, double g) {
    dens = d;
    this->g = g;
}
double World::getDensity(){
    return dens;
}
double World::getGravity(){
    return g;
}
