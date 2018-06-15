//
// Created by kakise on 6/10/18.
//

#ifndef IDMSIM_VEHICLES_H
#define IDMSIM_VEHICLES_H


class Vehicle {
public:
    Vehicle(double x, double v, double a);

    double x();

    double v();

    double a();

private:
    double m_x;
    double m_v;
    double m_a;
};


#endif //IDMSIM_VEHICLES_H
