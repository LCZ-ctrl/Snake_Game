// food.h
#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <deque>
#include <vector>
#include <raylib.h>

// 食物类定义
class Food {
public:
    Vector2 position; // 食物位置
    Texture2D texture; // 食物纹理
    bool isHardMode = false; // 是否困难模式
    // 构造函数：加载食物图片并生成不与蛇重叠的随机位置
    Food(std::deque<Vector2> snakeBody);
    // 析构函数：卸载纹理
    ~Food();
    // 绘制食物，颜色根据模式（困难模式下使用暗红色）进行着色
    void Draw();
    // 生成随机单元格位置
    Vector2 GenerateRandomCell();
    // 生成随机位置，确保不与蛇身或障碍物重叠
    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody, const std::vector<Vector2>& obstacles = {});
};

#endif // FOOD_H