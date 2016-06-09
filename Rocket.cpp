/* 
 * File:   Rocket.cpp
 * Author: student
 * 
 * Created on May 5, 2016, 11:10 AM
 */

#include "Rocket.h"

Rocket::Rocket(double m /*Mass*/, double cx /*Horizontal Coefficient of friction*/, 
        double cy /*Vertical Coefficient of friction*/, double ax /*Horizontal cross-sectional area*/, 
        double ay /*Vertical Cross-sectional area*/, double t /*Thrust*/, double b /*Burn time*/, double f) : super(m, cx, cy, ax, ay){
    thrust = t;
    burn = b;
    flow = f;
}

double Rocket::getThrust() {
    return thrust;
}

double Rocket::getBurn() {
    return burn;
}

double Rocket::getFlow(){
    return flow;
}




