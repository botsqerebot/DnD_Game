#ifndef BACKGROUNDS
#define BACKGROUNDS

#include "raylib.h"

#define MAX_BACKGROUNDS 2

Texture2D backgroundTextures[MAX_BACKGROUNDS];

void loadBackgroundTextures();
void changeBackgroundTexture(int backgroundID);

#endif