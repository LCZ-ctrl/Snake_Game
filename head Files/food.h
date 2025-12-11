#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <deque>
#include <vector>
#include <raylib.h>

class Food {
public:
    Vector2 position;
    Texture2D texture;
    bool isHardMode = false;

    Food(std::deque<Vector2> snakeBody);
    ~Food();

    void Draw();
    Vector2 GenerateRandomCell();
    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody, const std::vector<Vector2>& obstacles = {});
};

#endif
