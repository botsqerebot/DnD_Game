#include "raylib.h"

const char *whiteMan = "whiteMan.png";
const char *grayMan = "grayMan.png";
Texture2D characterTexture;

void setCharacterTextures(void *userData)
{
    const char *fileName = (const char *)userData;
    characterTexture = LoadTexture(TextFormat("People/%s", fileName));
}

// void LoadCharacters() {}