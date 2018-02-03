#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <iostream>
#include <stdlib.h>
#include <SDL.h>

class PongBall {
public:
    PongBall();
    PongBall(int x, int y);
    ~PongBall();

    void draw(SDL_Renderer *renderer);
    void move();

private:
    int mX;
    int mY;
};

#endif