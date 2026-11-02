#include <iostream>
#include <string>

extern "C" {
    #include "raylib.h"
}

#include "resource_dir.h"

int main ()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    InitWindow(800, 600, "Hello Raylib");

    SetExitKey(KEY_NULL);

    SearchAndSetResourceDir("resources");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Hello World", 200, 200, 20, WHITE);

        std::string frameTime = TextFormat("%.4f", GetFrameTime());
        DrawText(frameTime.c_str(), 100, 10, 20, WHITE);

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
