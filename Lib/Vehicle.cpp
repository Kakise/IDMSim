//
// Created by kakise on 6/10/18.
//

#include "Vehicle.h"

/// Class used to represent vehicles
/// \param x Current longitudinal position in m
/// \param v Current speed in m/s
/// \param a  Current acceleration in m/s²
Vehicle::Vehicle(double x, double v, double a) {
    m_x = x;
    m_v = v;
    m_a = a;
}

double Vehicle::v() {
    return m_v;
}

double Vehicle::x() {
    return m_x;
}

double Vehicle::a() {
    return m_a;
}
