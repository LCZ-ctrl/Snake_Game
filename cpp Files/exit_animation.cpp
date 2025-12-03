// exit_animation.cpp
#include "exit_animation.h"
#include <raymath.h>

bool exitAnimationActive = false;
float exitAnimationStartTime = 0.0f;
std::vector<ExitBubble> exitBubbles;

void GenerateExitBubbles(int count) {
    exitBubbles.clear();
    for (int i = 0; i < count; i++) {
        ExitBubble b;
        // x 坐标在屏幕内留一定边距随机生成
        b.x = (float)GetRandomValue(50, GetScreenWidth() - 50);
        // y 坐标从屏幕底部稍下方随机生成
        b.y = (float)GetRandomValue(GetScreenHeight(), GetScreenHeight() + 100);
        // 上升速度（原始值较慢）
        b.speed = (float)GetRandomValue(30, 80) / 2.0f;
        // 气泡大小随机生成
        b.size = (float)GetRandomValue(10, 30);
        exitBubbles.push_back(b);
    }
}

void DrawExitAnimation() {
    // 计算退出动画已持续时间
    float elapsed = GetTime() - exitAnimationStartTime;
    // 3 秒后退出程序
    if (elapsed >= 3.0f) exit(0);
    // 更新气泡位置，每个气泡上升（乘以 3.0f 加速上升速度）
    float frameTime = GetFrameTime();
    for (auto& b : exitBubbles) {
        b.y -= b.speed * frameTime * 3.0f;
        // 如果气泡上升超出屏幕上方，则从屏幕底部重新生成
        if (b.y + b.size < 0) {
            b.y = (float)GetScreenHeight() + b.size;
            b.x = (float)GetRandomValue(50, GetScreenWidth() - 50);
        }
    }
    BeginDrawing();
    ClearBackground(BLACK); // 黑色背景
    // 在屏幕正中间显示白色大字 "Thank you for playing"
    const char* exitText = "Thanks for playing";
    int fontSize = 50;
    int textWidth = MeasureText(exitText, fontSize);
    DrawText(exitText, (GetScreenWidth() - textWidth) / 2, GetScreenHeight() / 2 - fontSize / 2, fontSize, WHITE);
    // 绘制所有粉红色气泡
    for (auto& b : exitBubbles) {
        DrawCircle((int)b.x, (int)b.y, b.size, PINK);
    }
    EndDrawing();
}