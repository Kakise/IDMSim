#include <iostream>
#include <random>
#include "Lib/IDM.h"
#include "Lib/Vehicle.h"

int main() {
    IDM model = IDM(130 / 3.6f, 1.8f, 78.0f, 0.3f, 2.0f);
    std::vector<Vehicle> Cars;

    Cars.emplace_back(Vehicle(0, 130 / 3.6, 0));

    std::cout << Cars.at(0).v() << std::endl;
    return 0;
}