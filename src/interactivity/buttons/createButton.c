#include "raylib.h"
#include "stdio.h"

typedef void (*ButtonCallback)(void *userData);

void buttonFunction(int btnWidth, int btnHeight, int btnX, int btnY, int btnID, ButtonCallback callback, void *userdata)
{
    int ID = btnID;
    Rectangle buttonRect = {btnX, btnY, btnWidth, btnHeight};

    bool mouseOverButton = CheckCollisionPointRec(GetMousePosition(), buttonRect);
    if (mouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        TraceLog(LOG_INFO, "Button %d clicked", ID);
        // use a function i want to pass down using the parameters
        if (callback != NULL)
            callback(userdata);
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
