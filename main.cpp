#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Lib/lib.h"

int main() {
    IDM model = IDM(130 / 3.6f, 1.8f, 78.0f, 0.3f, 2.0f);
    std::vector<Vehicle> Cars;

    Cars.emplace_back(Vehicle(0, 130 / 3.6, 0));

    std::cout << "[DEBUG] La vitesse de la première voiture est: " << Cars.at(0).v() << " mètres par secondes." << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "[ERREUR] Erreur d'initialisation de la SDL." << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}