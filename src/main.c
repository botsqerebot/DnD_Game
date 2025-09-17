#include "raylib.h"
#include "interactivity/buttons/createButton.h"
#include "background/setBackground.h"
#include "characters/loadCharacterTextures.h"
#include "startup/initi.h"

int main()
{
	initilizeStartup();
	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		BeginDrawing();
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// Draw the background texture
		changeBackgroundTexture(&currentBg);
		buttonFunction(150, 50, 100, 200, 1, setBackground, &bg1);
		buttonFunction(150, 50, 100, 300, 2, setBackground, &bg2);
		buttonFunction(150, 50, 100, 400, 3, setCharacterTextures, (void *)whiteMan);
		buttonFunction(150, 50, 100, 500, 4, setCharacterTextures, (void *)grayMan);

		ViewCharacters(0, 200);

		drawButton(150, 50, 100, 200, "Hello", BLUE, ORANGE, 1);
		drawButton(150, 50, 100, 300, "World!", GRAY, ORANGE, 2);
		drawButton(150, 50, 100, 400, "Character!", GRAY, ORANGE, 3);
		drawButton(150, 50, 100, 500, "Character2!", GRAY, ORANGE, 4);
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	for (int i = 0; i < MAX_BACKGROUNDS; i++)
	{
		UnloadTexture(backgroundTextures[i]);
	}
	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
