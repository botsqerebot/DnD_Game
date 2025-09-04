#include "raylib.h"

// #include "../resources/Colors/colors.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir
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
	Texture background = LoadTexture("Backgrounds/Elvebakken.jpg");
	Rectangle src = {0, 0, background.width, background.height};
	Vector2 origin = {0, 0};

	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		BeginDrawing();
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		Rectangle dst = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
		DrawTexturePro(background, src, dst, origin, 0.0f, WHITE);

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// unload our texture so it can be cleaned up
	UnloadTexture(background);
	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
