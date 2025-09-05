#ifndef createBTN
#define createBTN

#include "raylib.h"

void buttonFunction(int btnWidth, int btnHeight, int btnX, int btnY, const char *btnText, Color btnColor, int btnID);
void drawButton(int btnWidth, int btnHeight, int btnX, int btnY, const char *btnText, Color btnColor, Color btnHoverColor, int btnID);

#endif