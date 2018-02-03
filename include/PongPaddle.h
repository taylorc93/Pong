#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <iostream>
#include <stdlib.h>
#include <SDL.h>

class PongPaddle {
public:
    PongPaddle();
    PongPaddle(int x, int y);
    ~PongPaddle();

    void draw(SDL_Renderer *renderer);

private:
    int mX;
    int mY;
};

#endif