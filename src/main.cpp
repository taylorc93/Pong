#include <iostream>
#include <stdlib.h>
#include <SDL.h>
#include "PongWindow.h"

void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void cleanup() {
    SDL_Quit();
}

int main(int, char**) {
    initSDL();

    PongWindow window = PongWindow();

    bool quit = false;
    while (!quit) {
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        std::cout << "Up" << std::endl;
                        window.updatePaddle(true);
                        break;
                    case SDLK_DOWN:
                        std::cout << "Down" << std::endl;
                        window.updatePaddle(false);
                        break;
                    default:
                        std::cout << "Other" << std::endl;
                        break;
                }
            }
        }

        window.draw();
    }

    cleanup();
    return 0;
}