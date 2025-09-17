#ifndef BACKGROUNDS
#define BACKGROUNDS

#include "raylib.h"

#define MAX_BACKGROUNDS 2

Texture2D backgroundTextures[MAX_BACKGROUNDS];
int bg1;
int bg2;
int currentBg;
void setBackground(void *userData);
void loadBackgroundTextures();
void changeBackgroundTexture(void *userData);

#endif