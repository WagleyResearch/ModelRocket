/* 
 * File:   Projectile.cpp
 * Author: student
 * 
 * Created on May 6, 2016, 3:49 PM
 */

#include "Projectile.h"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>

Projectile::Projectile(double m /*Mass*/, double cx /*Horizontal Coefficient of friction*/,
        double cy /*Vertical Coefficient of friction*/, double ax /*Horizontal cross-sectional area*/,
        double ay /*Vertical Cross-sectional area*/) {
    mass = m;
    coefx = cx;
    coefy = cy;
    areax = ax;
    areay = ay;
    distx = 0;
    disty = 0;
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

double Projectile::getDistX() {
    return distx;
}

double Projectile::getDistY() {
    return disty;
}

double Projectile::getAreaX() {
    return areax;
}

double Projectile::getAreaY() {
    return areay;
}

void Projectile::setDistY(double dist) {
    disty = dist;
}

void Projectile::setDistX(double dist) {
    distx = dist;
}

void Projectile::setMass(double mass) {
    this->mass = mass;
}
/*
void Projectile::openPath() {
    FILE *pipe = popen("/usr/local/bin/gnuplot --persist", "w");
    fprintf(pipe, "\n");
    fprintf(pipe, "set autoscale;\n");
    fprintf(pipe, "set multiplot;\n");
}

void Projectile::graphPath() {
    fprintf(pipe, "plot '-' w p ls %i\n", pointCount);
    fprintf(pipe, "%f %f\n", distx, disty);
    fprintf(pipe, "e;\n");

    pointCount++;

}

void Projectile::closePath() {
    fflush(pipe);
    std::cin.ignore();
    fclose(pipe);
}
*/
