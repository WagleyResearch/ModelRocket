/* 
 * File:   Rocket.cpp
 * Author: student
 * 
 * Created on May 5, 2016, 11:10 AM
 */

#include "Rocket.h"

Rocket::Rocket(double m, double c, double a, double t, double b) {
    mass = m;
    coef = c;
    area = a;
    thrust = t;
    burn = b;
}
double Rocket::getMass(){
    return mass;
}
double Rocket::getDrag(){
    return coef;
}
double Rocket::getArea(){
    return area;
}
double Rocket::getThrust(){
    return thrust;
}
double Rocket::getBurn(){
    return burn;
}



