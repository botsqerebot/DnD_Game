#include "raylib.h"

Vector2 GetScaledMousePosition(void)
{
    Vector2 mouse = GetMousePosition();
    float scaleX = (float)GetRenderWidth() / (float)GetScreenWidth();
    float scaleY = (float)GetRenderHeight() / (float)GetScreenHeight();
    mouse.x *= scaleX;
    mouse.y *= scaleY;
    return mouse;
}