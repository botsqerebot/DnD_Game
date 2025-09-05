/* // Initalization
Rectangle buttonRect = { 100, 100, 150, 50 };
const char* buttonText = "Click Me!";
Color buttonColor = BLUE; // Default color

// Game Loop
while (!WindowShouldClose())
{
    // Update
    bool mouseOverButton = CheckCollisionPointRec(GetMousePosition(), buttonRect);

    if (mouseOverButton)
    {
        buttonColor = LIGHTGRAY; // Hover color
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Button clicked, perform action
            buttonColor = DARKGRAY; // Pressed color
            TraceLog(LOG_INFO, "Button Clicked!");
        }
    }
    else
    {
        buttonColor = BLUE; // Normal color
    }

    // Drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangleRec(buttonRect, buttonColor);
    DrawText(buttonText, buttonRect.x + 20, buttonRect.y + 15, 20, BLACK); // Adjust text position as needed

    EndDrawing();
} */
#include "raylib.h"
#include "stdio.h"

#include "../mouse/mouseScaling.h"

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
