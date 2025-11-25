// snake.cpp
#include "snake.h"
#include "config.h"

void Snake::Draw() {
    for (unsigned int i = 0; i < body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = { offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize };
        DrawRectangleRounded(segment, 0.4, 6, darkGreen);
    }
}

void Snake::Reset() {
    body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
    direction = { 1,0 };
    nextDirection = { 1,0 };
}

void Snake::UpdateDirection() {
    // 两个方向相加如果不为 0，则不允许180°反转
    if ((nextDirection.x + direction.x != 0) || (nextDirection.y + direction.y != 0)) {
        direction = nextDirection;
    }
}