/* 
 * File:   Rocket.cpp
 * Author: student
 * 
 * Created on May 5, 2016, 11:10 AM
 */

#include "Rocket.h"

Rocket::Rocket(double m /*Mass*/, double cx /*Horizontal Coefficient of friction*/, 
        double cy /*Vertical Coefficient of friction*/, double ax /*Horizontal cross-sectional area*/, 
        double ay /*Vertical Cross-sectional area*/, double t /*Thrust*/, double b /*Burn time*/) {
    mass = m;
    coefx = cx;
    coefy = cy;
    areax = ax;
    thrust = t;
    burn = b;
}

double Rocket::getMass() {
    return mass;
}

double Rocket::getDragX() {
    return coefx;
}

double Rocket::getDragY() {
    return coefy;
}

double Rocket::getAreaX() {
    return areax;
}

double Rocket::getAreaY() {
    return areay;
}

double Rocket::getThrust() {
    return thrust;
}

double Rocket::getBurn() {
    return burn;
}



