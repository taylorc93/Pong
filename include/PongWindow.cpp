#include "PongWindow.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

PongWindow::PongWindow() {
    mWindow = SDL_CreateWindow(
        "SDL Tutorial",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!mWindow) {
        std::cout << "SDL_Window Init Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    if (!mRenderer) {
        std::cout << "SDL_Renderer Init Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

PongWindow::~PongWindow() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
}

void PongWindow::draw() {
    // Initialize the white background
    SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(mRenderer);

    // values are x, y, width, and height
    SDL_Rect paddleRect = { 0, 20, 20, 100 };
    SDL_SetRenderDrawColor(mRenderer, 0x0, 0x0, 0x0, 0x0);
    SDL_RenderFillRect(mRenderer, &paddleRect);

    SDL_RenderPresent(mRenderer);
}
