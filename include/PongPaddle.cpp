#include "PongPaddle.h"

const int WIDTH = 20;
const int HEIGHT = 80;

PongPaddle::PongPaddle() {
    mX = 0;
    mY = 0;
}

PongPaddle::PongPaddle(int x, int y) {
    mX = x;
    mY = y;
}

PongPaddle::~PongPaddle() {

}

void PongPaddle::draw(SDL_Renderer *renderer) {
    // values are x, y, width, and height
    SDL_Rect paddleRect = { mX, mY, WIDTH, HEIGHT };
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
    SDL_RenderFillRect(renderer, &paddleRect);
}
