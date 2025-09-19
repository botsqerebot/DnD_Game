#include "raylib.h"
#include "background/setBackground.h"
#include "startup/initi.h"
#include "states/home/homeMeny.h"
#include "states/game/gameState.h"
#include "states/setGameState.h"

int main()
{
	initilizeStartup();
	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		BeginDrawing();
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		int state = currentState;
		switch (state)
		{
		case 0:
			homeScreenMenu();
			break;
		case 1:
			gameScreenMenu();
			break;
		default:
			break;
		}

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
