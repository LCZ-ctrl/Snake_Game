// particle_system.cpp
#include "particle_system.h"
#include <raymath.h>

void ParticleSystem::Update(float deltaTime) {
    // 倒序遍历，确保删除时不会导致后续元素移动（减少拷贝开销）
    for (int i = particles.size() - 1; i >= 0; i--) {
        Particle& p = particles[i];
        p.lifetime += deltaTime;
        if (p.lifetime >= p.maxLifetime) {
            // 删除已经超时的粒子
            particles.erase(particles.begin() + i);
        }
        else {
            float lifeRatio = p.lifetime / p.maxLifetime;
            // 更新位置：当前位置加上速度*deltaTime
            p.position = Vector2Add(p.position, Vector2Scale(p.velocity, deltaTime));
            // 计算透明度随存活时间衰减
            float alpha = 1.0f - lifeRatio;
            p.color.a = (unsigned char)(alpha * 255);
            // 如果设置了随时间缩小，更新尺寸
            if (p.shrinkOverTime) {
                p.size *= (1.0f - deltaTime * 1.0f);
                if (p.size < 0.1f) p.size = 0.1f;
            }
        }
    }
}

void ParticleSystem::Draw() {
    for (auto& p : particles) {
        DrawCircleV(p.position, p.size, p.color);
    }
}

void ParticleSystem::SpawnParticles(Vector2 spawnPos, int count,
    float minSpeed, float maxSpeed,
    float minLifetime, float maxLifetime,
    float minSize, float maxSize,
    Color baseColor, bool shrink)
{
    for (int i = 0; i < count; i++) {
        Particle p;
        p.position = spawnPos;
        // 随机生成发射角度和速度
        float angle = GetRandomValue(0, 359) * DEG2RAD;
        float speed = GetRandomValue((int)(minSpeed * 100), (int)(maxSpeed * 100)) / 100.0f;
        p.velocity = { speed * cosf(angle), speed * sinf(angle) };
        p.lifetime = 0.0f;
        p.maxLifetime = GetRandomValue((int)(minLifetime * 100), (int)(maxLifetime * 100)) / 100.0f;
        p.size = GetRandomValue((int)(minSize * 10), (int)(maxSize * 10)) / 10.0f;
        p.color = baseColor;
        p.shrinkOverTime = shrink;
        particles.push_back(p);
    }
}