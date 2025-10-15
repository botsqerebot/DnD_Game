#ifndef STORYBUBBLE
#define STORYBUBBLE

#define GAMEWIDTH GetScreenWidth()
#define GAMEHEIGHT GetScreenHeight()
#define MARGIN 40
#define MARGINBOTTOM 20

void textBubble(char *TextContent, int ID);
void DrawTextWrapped(char *TextContent, Rectangle bounds, int fontSize, Color color);
void textBubbleWrapped(char *TextContent, int ID);
#endif