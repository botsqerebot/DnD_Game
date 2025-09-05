#include "raylib.h"

// #include "../resources/Colors/colors.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir
#include "interactivity/buttons/createButton.h"
#include "background/setBackground.h"

int main()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_BORDERLESS_WINDOWED_MODE | FLAG_WINDOW_RESIZABLE);

	// Get the usable area of the current monitor (excluding taskbar/menu bar)
	// Rectangle workArea = GetMonitorWorkarea(GetCurrentMonitor());

	int monitor = GetCurrentMonitor();
	int winWidth = GetMonitorWidth(monitor);
	int winHeight = GetMonitorHeight(monitor);

	// Create the window and OpenGL context
	InitWindow(winWidth, winHeight, "DnD");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	loadBackgroundTextures();

	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		buttonFunction(150, 50, 100, 200, 1);
		buttonFunction(150, 50, 100, 300, 2);
		BeginDrawing();
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// Draw the background texture
		changeBackgroundTexture(1);

		drawButton(150, 50, 100, 200, "Hello", BLUE, ORANGE, 1);
		drawButton(150, 50, 100, 300, "Button 2", GRAY, ORANGE, 2);
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
