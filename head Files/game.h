// game.h
#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include "particle_system.h"
#include <vector>
#include <raylib.h>
#include <raymath.h>

// 游戏类定义（包含游戏状态、音效、音乐、粒子系统、障碍物等）
class Game {
public:
    Snake snake = Snake(); // 蛇对象
    Food food = Food(snake.body); // 食物对象
    bool running = false; // 游戏是否运行
    bool paused = false; // 游戏是否暂停
    bool menuActive = true; // 是否处于主菜单状态
    bool modeSelectionActive = false;// 是否处于模式选择状态
    bool showInstructions = false; // 是否显示游戏说明窗口
    bool showAcknowledgement = false;// 是否显示致谢窗口
    int score = 0; // 当前得分
    bool newRecordAchieved = false; // 是否刷新最高纪录
    Sound eatSound; // 吃食物时的音效
    Sound wallSound; // 撞墙或撞到自身时的音效
    int mode = 1; // 游戏模式：1-普通，2-困难
    double moveInterval = 0.2; // 蛇移动的时间间隔
    std::vector<Vector2> obstacles; // 困难模式下生成的随机障碍物
    std::vector<Music> playlist; // 背景音乐列表
    int currentMusicIndex; // 当前播放音乐的索引
    bool musicPaused; // 背景音乐是否暂停
    float musicVolume1, musicVolume2, musicVolume3, musicVolume4, musicVolume5,
        musicVolume6, musicVolume7, musicVolume8, musicVolume9, musicVolume10, musicVolume11, musicVolume12;
    std::vector<float> musicDurations; // 各音乐的时长
    float eatVolume, wallVolume; // 音效音量
    int finalScore = 0; // 游戏结束时的得分
    ParticleSystem particleSystem; // 粒子系统
    float screenShakeTimer = 0.0f; // 屏幕震动计时器
    float screenShakeDuration = 0.0f; // 震动持续时间
    float screenShakeMagnitude = 0.0f; // 震动幅度
    // 构造函数：初始化音频设备、加载音效和音乐，并启动第一首音乐
    Game();
    // 析构函数：卸载所有音效、音乐并关闭音频设备
    ~Game();
    // 生成障碍物（困难模式下），确保新障碍物不与蛇或食物重叠
    void GenerateObstacles();
    // 生成随机障碍物位置
    Vector2 GenerateRandomCellForObstacles();
    // 启动屏幕震动效果
    void StartScreenShake(float duration, float magnitude);
    // 计算屏幕震动偏移量
    Vector2 GetScreenShakeOffset();
    // 更新屏幕震动计时器
    void UpdateScreenShake(float deltaTime);
    // 撞击时生成碰撞粒子效果
    void SpawnCollisionParticles();
    // 绘制整个游戏画面，包括蛇、食物、障碍物、粒子效果和覆盖层
    void Draw();
    // 更新游戏逻辑：检测碰撞、更新蛇体、生成粒子效果和更新分数
    void Update(float deltaTime);
    // 生成“原子弹”粒子效果（困难模式游戏结束时使用）
    void SpawnAtomicBombParticles();
    // 游戏结束处理：检测是否刷新高分、播放撞击音效、启动震动和粒子特效
    void GameOver();
    // 切换暂停状态
    void Pause();
    // 返回主菜单，并重置游戏状态
    void ReturnToMenu();
};

#endif // GAME_H