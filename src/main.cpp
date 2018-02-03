#include <iostream>
#include <stdlib.h>
#include <SDL.h>
#include "asset_path.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

SDL_Window *initWindow() {
    SDL_Window *window = SDL_CreateWindow(
        "SDL Tutorial",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cout << "SDL_Window Init Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    return window;
}

void fillWindow(SDL_Window *window) {
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillRect(
        surface,
        NULL,
        SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF)
    );

    SDL_UpdateWindowSurface(window);
}

void cleanup(SDL_Window *window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int, char**) {
    initSDL();

    SDL_Window *window = initWindow();
    fillWindow(window);

    bool quit = false;
    while (!quit) {
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    cleanup(window);
    return 0;
}