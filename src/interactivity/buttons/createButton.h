#ifndef CREATEBUTTONS
#define CREATEBUTTONS

#include "raylib.h"
#include "stdio.h"
typedef void (*ButtonCallback)(void *userData);
void buttonFunction(int btnWidth, int btnHeight, int btnX, int btnY, int btnID, ButtonCallback callback, void *userdata);
void drawButton(int btnWidth, int btnHeight, int btnX, int btnY, const char *btnText, Color btnColor, Color btnHoverColor, int btnID);
void buttonV2(int btnWidth, int btnHeight, int btnX, int btnY, const char *btnText, Color btnColor, Color btnHoverColor, ButtonCallback callback, void *userdata, int btnID);

#endif