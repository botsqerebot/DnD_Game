#include "raylib.h"
#include "stdio.h"

void buttonFunction(int btnWidth, int btnHeight, int btnX, int btnY, int btnID)
{
    int ID = btnID;
    Rectangle buttonRect = {btnX, btnY, btnWidth, btnHeight};

    bool mouseOverButton = CheckCollisionPointRec(GetMousePosition(), buttonRect);
    if (mouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        TraceLog(LOG_INFO, "Button %d clicked", ID);
        // printf("Button %d clicked", ID);
    }
}

void drawButton(int btnWidth, int btnHeight, int btnX, int btnY, const char *btnText, Color btnColor, Color btnHoverColor, int btnID)
{
    Rectangle buttonRect = {btnX, btnY, btnWidth, btnHeight};
    Color buttonColor = btnColor;
    const char *buttonText = btnText;

    bool mouseOverButton = CheckCollisionPointRec(GetMousePosition(), buttonRect);
    if (mouseOverButton)
    {
        buttonColor = btnHoverColor;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            buttonColor = LIGHTGRAY;
        }
    }

    DrawRectangleRec(buttonRect, buttonColor);
    DrawText(buttonText, buttonRect.x + 20, buttonRect.y + 15, 20, BLACK); // Adjust text position as needed
}
