#include "raylib.h"

const char *whiteMan = "whiteMan.png";
const char *grayMan = "grayMan.png";
Texture2D characterTexture;
bool characterVisible = false;

const int characterPositions[][2] = {
    {200, 200},
    {300, 200},
    {400, 200},
    {500, 200}};

void setCharacterTextures(void *userData)
{
    const char *fileName = (const char *)userData;
    characterTexture = LoadTexture(TextFormat("People/%s", fileName));
    characterVisible = true;
}

void ViewCharacters(int x, int y)
{
    if (characterVisible)
    {
        // const char *fileName = (const char *)userData;
        DrawTexture(characterTexture, x, y, WHITE);
        TraceLog(LOG_INFO, "Viewing Character");
    }
}