#include <cmath>
#include <iostream>
#include <string>

#include "raylib.h"
#include "raymath.h"

static constexpr int WindowWidth  = 1280;
static constexpr int WindowHeight = 720;
static constexpr const char* WindowTitle = "RLZ - Raylib Learing Zone";

int main ()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    InitWindow(WindowWidth, WindowHeight, WindowTitle);

    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    float brushRadius = 8.f;
    static constexpr float MinimalBallRadius = 1.f;
    static constexpr float MaximalBallRadius = 50.f;

    RenderTexture canvas = LoadRenderTexture(WindowWidth, WindowHeight);

    BeginTextureMode(canvas);
        ClearBackground(BLACK);
    EndTextureMode();

    Vector2 prevMousePosition = GetMousePosition();

    while (!WindowShouldClose())
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
            BeginTextureMode(canvas);
                ClearBackground(BLACK);
            EndTextureMode();
        }

        if (IsKeyPressed(KEY_Q) || IsKeyPressedRepeat(KEY_Q)) {
            brushRadius = std::max(brushRadius - 0.5f, MinimalBallRadius);
        }
        if (IsKeyPressed(KEY_E) || IsKeyPressedRepeat(KEY_E)) {
            brushRadius = std::min(brushRadius + 0.5f, MaximalBallRadius);
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            BeginTextureMode(canvas);
                DrawCircleV(GetMousePosition(), brushRadius, RAYWHITE);
                DrawCircleV(prevMousePosition, brushRadius, RAYWHITE);
                DrawLineEx(prevMousePosition, GetMousePosition(), brushRadius * 2.f, RAYWHITE);
            EndTextureMode();
        }

        prevMousePosition = GetMousePosition();


        // render

        BeginDrawing();

            ClearBackground(BLACK);

            DrawTextureRec(canvas.texture, Rectangle{ 0.f, 0.f, static_cast<float>(canvas.texture.width), static_cast<float>(-canvas.texture.height) }, Vector2Zero(), WHITE);

            DrawCircleLinesV(GetMousePosition(), brushRadius, LIME);

        EndDrawing();
    }

    UnloadRenderTexture(canvas);

    CloseWindow();
    return 0;
}
