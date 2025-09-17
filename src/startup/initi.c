#include "raylib.h"
#include "resource_dir.h" // utility header for SearchAndSetResourceDir
#include "../background/setBackground.h"

void initilizeStartup()
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
}