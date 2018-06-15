//
// Created by kakise on 6/10/18.
//

#include <cstdlib>
#include <random>
#include <algorithm>
#include "IDM.h"

///
/// \param a float
/// \param b float
/// \return Minimum of two floats
float minf(float a, float b) {
    return a < b ? a : b;
}

/// Intelligent Driver Model
/// \param v0 Desired speed in m/s
/// \param T Time headway in s. 1.8s is a great value.
/// \param s0 Minimum gap in m
/// \param a Maximum acceleration in m/s²
/// \param b Comfortable deceleration in m/s²
IDM::IDM(float v0, float T, double s0, float a, float b) {
    m_v0 = v0;
    m_T = T;
    m_s0 = s0;
    m_a = a;
    m_b = b;
}

/// This function calculates the acceleration using the IDM model.
/// \param s Current gap in m
/// \param v Current speed in m/s
/// \param vl Leading speed in m/s
/// \return The new acceleration value
double IDM::a(double s, double v, double vl) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    if (s < 0.0001) {
        return -bmax;
    }

    double accRnd = noiseAcc * dist(mt) * alpha_v0;

    double v0eff = minf(m_v0, minf(speedlimit, speedmax));

    double accFree;

    accFree = m_a * (1 - (v < v0eff ? pow(v / v0eff, 4) : v / v0eff));

    double sstar = m_s0 + std::max(0.0d, v * m_T + 0.5 * v * (v - vl) / sqrt(m_a * m_b));
    double accInt = -m_a * pow(sstar / std::max(s, m_s0), 2);

    if (v0eff < 0.00001) {
        return 0;
    } else {
        return std::max(-bmax, accFree + accInt + accRnd);
    }
}
