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

    mLeftPaddle = PongPaddle(0, 20);
    mRightPaddle = PongPaddle(SCREEN_WIDTH - 20, SCREEN_HEIGHT - 100);
}

PongWindow::~PongWindow() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
}

void PongWindow::draw() {
    // Initialize the white background
    SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(mRenderer);

    mLeftPaddle.draw(mRenderer);
    mRightPaddle.draw(mRenderer);

    SDL_RenderPresent(mRenderer);
}
