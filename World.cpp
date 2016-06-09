/* 
 * File:   World.cpp
 * Author: student
 * 
 * Created on May 5, 2016, 11:24 AM
 */

#include "World.h"
#include "Rocket.h"

World::World(double d /*Density of air*/, double g /*Gravitational acceleration*/) {
    dens = d;
    this->g = g;
}
World::World(){
    dens = 1.223;
    g = 9.8;
}
double World::getDensity(){
    return dens;
}
double World::getGravity(){
    return g;
}
