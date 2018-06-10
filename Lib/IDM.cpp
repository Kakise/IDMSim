//
// Created by kakise on 6/10/18.
//

#include <cstdlib>
#include <random>
#include <algorithm>
#include "IDM.h"

/* Intelligent Driver Model
*
* @param v0:   desired speed            [m/s]
* @param T:    time headway             [s]  -> ~1.8s is a great value
* @param s0:   minimum gap              [m] -> 78 meters in France for 130km/h (A calculer automatiquement?)
* @param a:    maximum acceleration     [m/s²]
* @param b:    comfortable deceleration [m/s²]
*/

float minf(float a, float b) {
    return a < b ? a : b;
}

// Class constructor
IDM::IDM(float v0, float T, float s0, float a, float b) {
    m_v0 = v0;
    m_T = T;
    m_s0 = s0;
    m_a = a;
    m_b = b;
}

// This function calculates the acceleration of a vehicle following the IDM
float IDM::a(float s, float v, float vl) {
    // Randomness
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    if (s < 0.0001) {
        return -bmax;
    }

    float accRnd = (noiseAcc * ((float) (dist(mt) / double(RAND_MAX)))) * alpha_v0;

    float v0eff = minf(m_v0, minf(speedlimit, speedmax));

    float accFree;

    accFree = m_a * (1 - (v < v0eff ? (float) pow(v / v0eff, 4) : v / v0eff));

    double sstar = m_s0 + std::max(0.0d, v * m_T + 0.5 * v * (v - vl) / sqrt(m_a * m_b));
    float accInt = -m_a * (float) pow(sstar / std::max(s, m_s0), 2);

    if (v0eff < 0.00001) {
        return 0;
    } else {
        return std::max(-bmax, accFree + accInt + accRnd);
    }
}
