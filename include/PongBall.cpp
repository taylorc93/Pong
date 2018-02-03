#include "PongBall.h"

const int WIDTH = 20;
const int HEIGHT = 20;

PongBall::PongBall() {
    mX = 0;
    mY = 0;
}

PongBall::PongBall(int x, int y) {
    mX = x;
    mY = y;
}

PongBall::~PongBall() {

}

void PongBall::draw(SDL_Renderer *renderer) {
    // values are x, y, width, and height
    SDL_Rect ballRect = { mX, mY, WIDTH, HEIGHT };
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
    SDL_RenderFillRect(renderer, &ballRect);
}

void PongBall::move() {

}
