#include "raylib.h"

#define MAX_BACKGROUNDS 2

Texture2D backgroundTextures[MAX_BACKGROUNDS];

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