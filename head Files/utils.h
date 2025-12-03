// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <deque>
#include <vector>
#include <raylib.h>
#include <raymath.h>

// 检查给定元素是否在 deque 中存在
bool ElementInDeque(Vector2 element, const std::deque<Vector2>& dq);

// 检查给定元素是否在 vector 中存在
bool ElementInVector(Vector2 element, const std::vector<Vector2>& vec);

// 检测是否经过指定时间间隔，用于定时事件（例如蛇的移动）
bool eventTriggered(double interval);

#endif // UTILS_H