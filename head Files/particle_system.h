// particle_system.h
#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <vector>
#include <raylib.h>

// 定义单个粒子的属性结构体
struct Particle {
    Vector2 position; // 位置
    Vector2 velocity; // 运动速度（方向与速率）
    float lifetime; // 已经存活的时间
    float maxLifetime; // 最大存活时间
    float size; // 尺寸（半径）
    Color color; // 颜色（包括透明度）
    bool shrinkOverTime; // 是否随时间缩小
};

// 粒子系统类，管理所有粒子的更新与绘制
class ParticleSystem {
public:
    std::vector<Particle> particles; // 存储所有活跃粒子
    // 更新所有粒子（使用倒序遍历优化删除操作）
    void Update(float deltaTime);
    // 绘制所有粒子（以圆形方式绘制）
    void Draw();
    // 生成一定数量的粒子，所有属性在给定范围内随机生成
    void SpawnParticles(Vector2 spawnPos, int count,
        float minSpeed, float maxSpeed,
        float minLifetime, float maxLifetime,
        float minSize, float maxSize,
        Color baseColor, bool shrink = false);
};

#endif // PARTICLE_SYSTEM_H