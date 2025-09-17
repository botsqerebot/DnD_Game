#ifndef createBTN
#define createBTN

#include "raylib.h"
typedef void (*ButtonCallback)(void *userData);
void buttonFunction(int btnWidth, int btnHeight, int btnX, int btnY, int btnID, ButtonCallback callback, void *userdata);
void drawButton(int btnWidth, int btnHeight, int btnX, int btnY, const char *btnText, Color btnColor, Color btnHoverColor, int btnID);

#endif