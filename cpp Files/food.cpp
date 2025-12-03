// food.cpp
#include "food.h"
#include "config.h"
#include "utils.h"

Food::Food(std::deque<Vector2> snakeBody) {
    Image image = LoadImage("Graphics/food.png");

    std::cout << "LoadImage returned data=" << (void*)image.data
        << " w=" << image.width << " h=" << image.height
        << " format=" << image.format << std::endl;

    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = GenerateRandomPos(snakeBody);
}

Food::~Food() {
    UnloadTexture(texture);
}

void Food::Draw() {
    Color foodTint = isHardMode ? darkRed : green;
    DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, foodTint);
}

Vector2 Food::GenerateRandomCell() {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{ x, y };
}

Vector2 Food::GenerateRandomPos(std::deque<Vector2> snakeBody, const std::vector<Vector2>& obstacles) {
    Vector2 pos = GenerateRandomCell();
    while (ElementInDeque(pos, snakeBody) || ElementInVector(pos, obstacles)) {
        pos = GenerateRandomCell();
    }
    return pos;
}