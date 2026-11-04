#include <cmath>
#include <iostream>
#include <string>

#include "raylib.h"
#include "raymath.h"

#include "resource_dir.h"

static constexpr int InitialWindowWidth  = 1280;
static constexpr int InitialWindowHeight = 720;
static constexpr const char* WindowTitle = "RLZ - Raylib Learing Zone";

static constexpr int MinimalWindowWidth  = 320;
static constexpr int MinimalWindowHeight = 240;

int main ()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    // SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);

    InitWindow(InitialWindowWidth, InitialWindowHeight, WindowTitle);

    // SetWindowMinSize(MinimalWindowWidth, MinimalWindowHeight);

    SetExitKey(KEY_NULL);

    SearchAndSetResourceDir("resources");

    float ballRadius = 20.f;

    Vector2 ballPosition{};
    ballPosition.x = InitialWindowWidth / 2;
    ballPosition.y = InitialWindowHeight / 2;

    while (!WindowShouldClose())
    {
        // update

        const float deltaTime = GetFrameTime();

        static constexpr float ballSpeed = 200.f;

        if (IsKeyDown(KEY_A)) {
            ballPosition.x -= ballSpeed * deltaTime;
        }
        if (IsKeyDown(KEY_D)) {
            ballPosition.x += ballSpeed * deltaTime;
        }
        if (IsKeyDown(KEY_W)) {
            ballPosition.y -= ballSpeed * deltaTime;
        }
        if (IsKeyDown(KEY_S)) {
            ballPosition.y += ballSpeed * deltaTime;
        }

        static constexpr float MinimalBallRadius = 12.f;
        static constexpr float MaximalBallRadius = 50.f;

        if (IsKeyPressedRepeat(KEY_LEFT_BRACKET)) {
            ballRadius = std::max(ballRadius - 0.5f, MinimalBallRadius);
        }
        if (IsKeyPressedRepeat(KEY_RIGHT_BRACKET)) {
            ballRadius = std::min(ballRadius + 0.5f, MaximalBallRadius);
        }

        ballPosition.x = Clamp(ballPosition.x, ballRadius, GetScreenWidth() - ballRadius);
        ballPosition.y = Clamp(ballPosition.y, ballRadius, GetScreenHeight() - ballRadius);

        // render

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Hello World", 200, 200, 20, WHITE);

        DrawCircleV(ballPosition, ballRadius, LIME);

        std::string frameTime = TextFormat("%.4f", GetFrameTime());
        DrawText(frameTime.c_str(), 100, 10, 20, WHITE);

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
