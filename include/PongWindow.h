#ifndef PONG_WINDOW_H
#define PONG_WINDOW_H

#include <iostream>
#include <stdlib.h>
#include <SDL.h>

class PongWindow {
public:
    PongWindow();
    ~PongWindow();

    void draw();

private:
    SDL_Window *mWindow;
    SDL_Renderer * mRenderer;
};

#endif