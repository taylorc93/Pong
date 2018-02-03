#ifndef PONG_WINDOW_H
#define PONG_WINDOW_H

#include <iostream>
#include <stdlib.h>
#include <SDL.h>
#include "PongPaddle.h"
#include "PongBall.h"

class PongWindow {
public:
    PongWindow();
    ~PongWindow();

    void draw();
    void updatePaddle(bool up);

private:
    SDL_Window *mWindow;
    SDL_Renderer * mRenderer;

    PongPaddle mLeftPaddle;
    PongPaddle mRightPaddle;
    PongBall mBall;
};

#endif