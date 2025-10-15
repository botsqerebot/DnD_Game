#include "raylib.h"
#include "stdio.h"

typedef void (*ButtonCallback)(void *userData);

// Combining the two functions over making it better and smaller code in total.
void buttonV2(int btnWidth, int btnHeight, int btnX, int btnY, const char *btnText, Color btnColor, Color btnHoverColor, ButtonCallback callback, void *userdata, int btnID)
{
    Rectangle buttonRect = {btnX, btnY, btnWidth, btnHeight};
    bool mouseOverButton = CheckCollisionPointRec(GetMousePosition(), buttonRect);

    // Color buttonColor = btnColor;
    Color buttonColor = mouseOverButton ? btnHoverColor : btnColor;
    const char *buttonText = btnText;

    if (mouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        TraceLog(LOG_INFO, "Button %d clicked", btnID);

        // use a function i want to pass down using the parameters
        if (callback != NULL)
            callback(userdata);
    }

    DrawRectangleRec(buttonRect, buttonColor);
    DrawText(buttonText, buttonRect.x + 20, buttonRect.y + 15, 20, BLACK); // Adjust text position as needed
}