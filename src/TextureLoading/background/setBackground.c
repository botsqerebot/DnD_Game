#include "raylib.h"

#define MAX_BACKGROUNDS 2

Texture2D backgroundTextures[MAX_BACKGROUNDS];

int bg1 = 0;
int bg2 = 1;

int currentBg = 0;

void setBackground(void *userData)
{
    int *bgIndex = (int *)userData;
    currentBg = *bgIndex;
}

void loadBackgroundTextures()
{
    const char *backgrounds[] = {"Elvebakken.jpg", "Space.jpg"};
    int numBackgrounds = sizeof(backgrounds) / sizeof(backgrounds[0]);

    for (int i = 0; i < numBackgrounds; i++)
    {
        backgroundTextures[i] = LoadTexture(TextFormat("Backgrounds/%s", backgrounds[i]));
        // Rectangle src and Vector2 origin can be created where you draw the texture
    }
}

void changeBackgroundTexture(void *userData)
{
    int *bgIndex = (int *)userData;
    Rectangle src = {0, 0, backgroundTextures[*bgIndex].width, backgroundTextures[*bgIndex].height};
    Rectangle dst = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
    Vector2 origin = {0, 0};
    DrawTexturePro(backgroundTextures[*bgIndex], src, dst, origin, 0.0f, WHITE);
};