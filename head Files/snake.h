// snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <raylib.h>

// 蛇类定义
class Snake {
public:
    // 初始蛇体由三个单元格构成
    std::deque<Vector2> body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
    Vector2 direction = { 1,0 }; // 初始运动方向为右
    Vector2 nextDirection = { 1,0 }; // 预备方向，初始与 direction 相同
    bool addSegment = false; // 是否在下次移动时增加新段
    // 绘制蛇，每个单元格绘制为带圆角的矩形
    void Draw();
    // 重置蛇体为初始状态
    void Reset();
    // 在移动前更新方向，只允许非180°反转
    void UpdateDirection();
};

#endif // SNAKE_H