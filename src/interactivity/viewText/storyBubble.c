#include "raylib.h"
#include <string.h>

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

void DrawTextWrapped(char *TextContent, Rectangle bounds, int fontSize, Color color)
{
    Font font = GetFontDefault();
    float spacing = 1.0f;
    float textOffsetY = 0;
    float textOffsetX = 0.0f;

    int textLenght = TextLength(TextContent);
    int lineStart = 0;

    for (int i = 0; i <= textLenght; i++)
    {
        char currentChar = (i < textLenght) ? TextContent[i] : '\0';

        // If we hit a space, newline, or end of text, we need to check if we should wrap
        if (currentChar == ' ' || currentChar == '\n' || i == textLenght)
        {
            // Measure the word from lineStart to current position
            char wordBuffer[256];
            int wordLength = i - lineStart;

            if (wordLength > 0 && wordLength < 255)
            {
                strncpy(wordBuffer, &TextContent[lineStart], wordLength);
                wordBuffer[wordLength] = '\0';

                float wordWidth = MeasureText(wordBuffer, fontSize);

                // Check if this word would overflow
                if (textOffsetX + wordWidth > bounds.width && textOffsetX > 0)
                {
                    // Wrap to next line before drawing this word
                    textOffsetY += fontSize + 5;
                    textOffsetX = 0;

                    // Check vertical bounds
                    if (textOffsetY + fontSize > bounds.height)
                        break;
                }

                // Draw the word
                DrawText(wordBuffer, bounds.x + textOffsetX, bounds.y + textOffsetY, fontSize, color);
                textOffsetX += wordWidth;
            }

            // Handle the space or newline
            if (currentChar == ' ')
            {
                float spaceWidth = MeasureText(" ", fontSize);
                textOffsetX += spaceWidth;
                lineStart = i + 1;
            }
            else if (currentChar == '\n')
            {
                textOffsetY += fontSize + 5;
                textOffsetX = 0;
                lineStart = i + 1;

                // Check vertical bounds
                if (textOffsetY + fontSize > bounds.height)
                    break;
            }
            else
            {
                // End of text
                break;
            }
        }
    }
}

void textBubbleWrapped(char *TextContent, int ID)
{
    int bubbleWidth = GAMEWIDTH - (MARGIN * 2);
    int bubbleHeight = 200;
    int bubbleHeightY = GAMEHEIGHT - MARGINBOTTOM - bubbleHeight;

    Rectangle bubbleSize = {MARGIN, bubbleHeightY, bubbleWidth, bubbleHeight};
    Rectangle textArea = {bubbleSize.x + 20, bubbleSize.y + 15, bubbleSize.width - 40, bubbleSize.height - 30};

    Color backgroundColor = GRAY;

    DrawRectangleRec(bubbleSize, backgroundColor);

    DrawRectangleLines(textArea.x, textArea.y, textArea.width, textArea.height, RED);

    DrawTextWrapped(TextContent, textArea, 20, BLACK);
}