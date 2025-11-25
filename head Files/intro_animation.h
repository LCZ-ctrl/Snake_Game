// intro_animation.h
#ifndef INTRO_ANIMATION_H
#define INTRO_ANIMATION_H

#include <iostream>
#include <vector>
#include <raylib.h>

// 定义开场动画状态
enum IntroState { TEXT_ANIMATION, LOGO_ANIMATION, INTRO_FINISHED };

// 绘制垂直渐变背景，颜色由 sin 和 cos 函数随时间变化生成
void DrawGradientBackground();

// 文本动画函数：每隔0.8秒逐个单词显示文本（背景黑色，文字白色）
void DrawIntroAnimation(float introTime, int screenWidth, int screenHeight);

// Logo动画函数：在黑色背景中显示 "LCZ"，文字与边框随时间放大
// 边框使用 DrawLineEx 分段绘制
void DrawLogoAnimation(float logoTime, int screenWidth, int screenHeight);

#endif // INTRO_ANIMATION_H