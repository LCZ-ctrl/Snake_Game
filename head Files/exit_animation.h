// exit_animation.h
#ifndef EXIT_ANIMATION_H
#define EXIT_ANIMATION_H

#include <vector>
#include <raylib.h>

// 标识是否进入退出动画状态
extern bool exitAnimationActive;
// 记录退出动画开始时间
extern float exitAnimationStartTime;

// 定义退出动画中气泡的结构体（这里用圆形模拟心形粉红色气泡）
struct ExitBubble {
    float x, y; // 气泡位置
    float speed; // 上升速度
    float size; // 气泡大小（半径）
};

// 存储退出动画中的气泡
extern std::vector<ExitBubble> exitBubbles;

// 生成指定数量的退出动画气泡
void GenerateExitBubbles(int count);

// 绘制退出动画界面
void DrawExitAnimation();

#endif // EXIT_ANIMATION_H