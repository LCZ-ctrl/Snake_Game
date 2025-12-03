// intro_animation.cpp
#include "intro_animation.h"
#include "config.h"
#include <cmath>

void DrawGradientBackground() {
    static float time = 0.0f;
    time += GetFrameTime();
    Color topColor = {
        (unsigned char)(127 + 128 * sin(time)),
        (unsigned char)(127 + 128 * sin(time + 2.0f)),
        (unsigned char)(127 + 128 * sin(time + 4.0f)),
        255
    };
    Color bottomColor = {
        (unsigned char)(127 + 128 * cos(time)),
        (unsigned char)(127 + 128 * cos(time + 2.0f)),
        (unsigned char)(127 + 128 * cos(time + 4.0f)),
        255
    };
    DrawRectangleGradientV(0, 0, GetScreenWidth(), GetScreenHeight(), topColor, bottomColor);
}

void DrawIntroAnimation(float introTime, int screenWidth, int screenHeight) {
    // 定义要显示的三行文本，每行以单词划分
    std::vector<std::vector<std::string>> introLines = {
        {"To", "my", "little", "cousins"},
        {"and"},
        {"my", "friends"}
    };
    // 计算总单词数
    int totalWords = 0;
    for (auto& line : introLines) {
        totalWords += line.size();
    }
    // 计算当前应显示的单词数（每0.8秒一个单词，最少显示1个单词）
    int wordsRevealed = (int)(introTime / 0.8f) + 1;
    if (wordsRevealed > totalWords) wordsRevealed = totalWords;
    // 根据已显示的单词数，逐行拼接要显示的文本
    int remaining = wordsRevealed;
    std::vector<std::string> linesToDraw;
    for (auto& lineWords : introLines) {
        int wordsForThisLine = 0;
        if (remaining > (int)lineWords.size()) {
            wordsForThisLine = lineWords.size();
            remaining -= lineWords.size();
        }
        else {
            wordsForThisLine = remaining;
            remaining = 0;
        }
        std::string lineText = "";
        for (int i = 0; i < wordsForThisLine; i++) {
            lineText += lineWords[i];
            if (i != wordsForThisLine - 1) lineText += " ";
        }
        linesToDraw.push_back(lineText);
    }
    Color textColor = WHITE;
    int fontSize = 40;
    int lineSpacing = 50;
    int totalTextHeight = linesToDraw.size() * lineSpacing;
    int startY = screenHeight / 2 - totalTextHeight / 2;
    // 居中绘制每一行文本
    for (size_t i = 0; i < linesToDraw.size(); i++) {
        if (!linesToDraw[i].empty()) {
            int textWidth = MeasureText(linesToDraw[i].c_str(), fontSize);
            int x = screenWidth / 2 - textWidth / 2;
            int y = startY + i * lineSpacing;
            DrawText(linesToDraw[i].c_str(), x, y, fontSize, textColor);
        }
    }
}

void DrawLogoAnimation(float logoTime, int screenWidth, int screenHeight) {
    const float totalLogoDuration = 3.5f;
    float effectiveTime = logoTime;
    if (effectiveTime > totalLogoDuration) {
        effectiveTime = totalLogoDuration;
    }
    float progress = effectiveTime / totalLogoDuration;
    float baseFontSize = 40.0f;
    float maxScale = 1.4f;
    float smoothProgress = progress * progress * (3 - 2 * progress);
    float scale = 1.0f + (maxScale - 1.0f) * smoothProgress;
    int fontSize = (int)(baseFontSize * scale);
    const char* logoText = "LCZ";
    int textWidth = MeasureText(logoText, fontSize);
    int textHeight = fontSize;
    int textX = screenWidth / 2 - textWidth / 2;
    int textY = screenHeight / 2 - textHeight / 2;
    DrawText(logoText, textX, textY, fontSize, WHITE);
    int margin = (int)(10 * scale);
    int rectX = textX - margin;
    int rectY = textY - margin;
    int rectWidth = textWidth + 2 * margin;
    int rectHeight = textHeight + 2 * margin;
    float perimeter = 2 * (rectWidth + rectHeight);
    float drawnLength = perimeter * progress;
    float thickness = 4.0f;
    float remaining = drawnLength;
    float topEdge = rectWidth;
    if (remaining > 0) {
        if (remaining < topEdge) {
            DrawLineEx(Vector2{ (float)rectX, (float)rectY },
                Vector2{ rectX + remaining, (float)rectY },
                thickness, darkRedColor);
            remaining = 0;
        }
        else {
            DrawLineEx(Vector2{ (float)rectX, (float)rectY },
                Vector2{ (float)(rectX + rectWidth), (float)rectY },
                thickness, darkRedColor);
            remaining -= topEdge;
        }
    }
    float rightEdge = rectHeight;
    if (remaining > 0) {
        if (remaining < rightEdge) {
            DrawLineEx(Vector2{ (float)(rectX + rectWidth), (float)rectY },
                Vector2{ (float)(rectX + rectWidth), rectY + remaining },
                thickness, darkRedColor);
            remaining = 0;
        }
        else {
            DrawLineEx(Vector2{ (float)(rectX + rectWidth), (float)rectY },
                Vector2{ (float)(rectX + rectWidth), (float)(rectY + rectHeight) },
                thickness, darkRedColor);
            remaining -= rightEdge;
        }
    }
    float bottomEdge = rectWidth;
    if (remaining > 0) {
        if (remaining < bottomEdge) {
            DrawLineEx(Vector2{ (float)(rectX + rectWidth), (float)(rectY + rectHeight) },
                Vector2{ rectX + rectWidth - remaining, (float)(rectY + rectHeight) },
                thickness, darkRedColor);
            remaining = 0;
        }
        else {
            DrawLineEx(Vector2{ (float)(rectX + rectWidth), (float)(rectY + rectHeight) },
                Vector2{ (float)rectX, (float)(rectY + rectHeight) },
                thickness, darkRedColor);
            remaining -= bottomEdge;
        }
    }
    float leftEdge = rectHeight;
    if (remaining > 0) {
        if (remaining < leftEdge) {
            DrawLineEx(Vector2{ (float)rectX, (float)(rectY + rectHeight) },
                Vector2{ (float)rectX, rectY + rectHeight - remaining },
                thickness, darkRedColor);
            remaining = 0;
        }
        else {
            DrawLineEx(Vector2{ (float)rectX, (float)(rectY + rectHeight) },
                Vector2{ (float)rectX, (float)rectY },
                thickness, darkRedColor);
            remaining -= leftEdge;
        }
    }
}