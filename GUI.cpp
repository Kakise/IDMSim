//
// Created by kakise on 6/15/18.
//

#include "GUI.h"

/// Only used for developement purposes.
void GUI::pause() {
    int ok = 1;
    SDL_Event event;

    while (ok) {
        SDL_WaitEvent(&event);
        switch(event.type) {
            default:

            case SDL_QUIT:
                ok = 0;
        }
    }
}

void GUI::update(std::vector<Vehicle> CarArr) {

}
