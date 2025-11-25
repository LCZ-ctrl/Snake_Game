// high_score.h
#ifndef HIGH_SCORE_H
#define HIGH_SCORE_H

#include <string>

// 定义高分记录文件夹和模式对应的记录文件路径
extern const std::string highScoreFolder;
extern const std::string mode1File;
extern const std::string mode2File;

// 创建保存高分记录的文件夹
void CreateHighScoreFolder();

// 根据模式读取高分记录，如果读取失败则返回 -1
int GetHighScoreForMode(int mode);

// 将当前分数写入对应模式的高分记录文件
void SetHighScoreForMode(int mode, int score);

#endif // HIGH_SCORE_H