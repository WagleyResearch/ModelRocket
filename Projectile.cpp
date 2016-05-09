/* 
 * File:   Projectile.cpp
 * Author: student
 * 
 * Created on May 6, 2016, 3:49 PM
 */

#include "Projectile.h"

Projectile::Projectile(double m /*Mass*/, double cx /*Horizontal Coefficient of friction*/,
        double cy /*Vertical Coefficient of friction*/, double ax /*Horizontal cross-sectional area*/,
        double ay /*Vertical Cross-sectional area*/) {
    mass = m;
    coefx = cx;
    coefy = cy;
    areax = ax;
    areay = ay;
}
double Projectile::getMass() {
    return mass;
}

double Projectile::getDragX() {
    return coefx;
}

double Projectile::getDragY() {
    return coefy;
}

double Projectile::getAreaX() {
    return areax;
}

double Projectile::getAreaY() {
    return areay;
}
void Projectile::setMass(double mass){
    this->mass = mass;
}


