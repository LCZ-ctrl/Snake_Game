// config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <raylib.h>

// 定义游戏中使用的颜色
extern Color green;
extern Color darkGreen;
extern Color darkRed;
extern Color darkRedColor;

// 定义网格单元格大小、数量及整体绘制偏移量
extern int cellSize;
extern int cellCount;
extern int offset;

// 用于定时控制的全局变量
extern double lastUpdateTime;

#endif // CONFIG_H