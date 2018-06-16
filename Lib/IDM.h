//
// Created by kakise on 6/10/18.
//

#ifndef IDMSIM_IDM_H
#define IDMSIM_IDM_H


#include "Vehicle.h"

class IDM {
public:
    IDM(float v0, float T, double s0, float a, float b);

    void update(std::vector<Vehicle> *CarArr, double dt);
    double a(double s, double v, double vl);

private:
    float m_v0, m_T, m_a, m_b;
    double m_s0;
    int alpha_v0 = 1;
    int speedlimit = 1000;
    int speedmax = 1000;
    double bmax = 18;
    float noiseAcc = 0.3f;
};


#endif //IDMSIM_IDM_H
