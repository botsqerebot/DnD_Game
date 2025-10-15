#include "raylib.h"

#define GAMEWIDTH GetScreenWidth()
#define GAMEHEIGHT GetScreenHeight()
#define MARGIN 40
#define MARGINBOTTOM 20

void textBubble(char *TextContent, int ID)
{
    int bubbleWidth = GAMEWIDTH - (MARGIN * 2);
    int bubbleHeight = 200;
    int bubbleHeightY = GAMEHEIGHT - MARGINBOTTOM - bubbleHeight;

    Rectangle bubbleSize = {MARGIN, bubbleHeightY, bubbleWidth, bubbleHeight};
    Color backgroundColor = GRAY;

    DrawRectangleRec(bubbleSize, backgroundColor);
    DrawText(TextContent, bubbleSize.x + 20, bubbleSize.y + 15, 20, BLACK);
}