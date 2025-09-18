#include "raylib.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir
#include "../background/setBackground.h"

void initilizeStartup()
{
    // Tell the window to use vsync and work on high DPI displays
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_BORDERLESS_WINDOWED_MODE | FLAG_WINDOW_RESIZABLE); // FLAG_WINDOW_RESIZABLE makes the first boot unaligned for the buttons.

    // Get the usable area of the current monitor (excluding taskbar/menu bar)
    // Rectangle workArea = GetMonitorWorkarea(GetCurrentMonitor());

    int monitor = GetCurrentMonitor();
    int winWidth = 1280; // GetMonitorWidth(monitor); //Setting this to a fixed value becuase then itll work with coordinates of the buttons and hud on startup and when going fullscreen itll be native resolution.
    int winHeight = 720; // GetMonitorHeight(monitor);

    // Create the window and OpenGL context
    InitWindow(winWidth, winHeight, "DnD");

    // Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
    SearchAndSetResourceDir("resources");

    Image icon = LoadImage("Icons/IconDnD.png");

    SetWindowIcon(icon);
    UnloadImage(icon);

    // Load a texture from the resources directory
    loadBackgroundTextures();
}