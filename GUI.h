//
// Created by kakise on 6/15/18.
//

#ifndef IDMSIM_GUI_H
#define IDMSIM_GUI_H

#include <SDL2/SDL.h>
#include <vector>
#include "Lib/Vehicle.h"

class GUI {
public:
    void pause();

    void update(std::vector<Vehicle> CarArr);
};


#endif //IDMSIM_GUI_H
