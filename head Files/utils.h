#ifndef UTILS_H
#define UTILS_H

#include <deque>
#include <vector>
#include <raylib.h>
#include <raymath.h>

bool ElementInDeque(Vector2 element, const std::deque<Vector2>& dq);
bool ElementInVector(Vector2 element, const std::vector<Vector2>& vec);
bool eventTriggered(double interval);

#endif
