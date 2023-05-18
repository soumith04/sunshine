#include "rlImGui.h"
#include "raylib.h"

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Sunshine");
    SetTargetFPS(60);

    // Variables needed to check collision between two Circles
    Vector2 circlePosition = { screenWidth / 2, screenHeight / 2 };
    Vector2 mousePosition;
    float circleRadius = 50;
    Color circleColor = RED;

    while (!WindowShouldClose())
    {
        // Code which was already here
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello World!", 16, 9, 20, RED);

        // 1. Draw a color-filled Rectangle
        DrawRectangle(100, 200, 150, 250, RED);

        // 2. Draw a color-filled Circle
        DrawCircle(250, 100, 25, BLUE);

        // 3. Draw a color-filled triangle
        DrawTriangle({ 100, 200 }, { 200, 200 }, { 150, 100 }, GREEN);

        // 4. Draws a color-filled Rectangle
        //DrawRectangle(100, 200, 150, 250, RED);

        // 5. Draws a line tickness
        //DrawLineEx(startPos, endPos, 30.0f, BLACK);

        // 6. Draws acurved line tickness
        //DrawLineBezier(startPos, endPos, 20.0f, BLUE);
        
        // 7. Draws a curved line with control on where the curve begins and ends
        // DrawLineBezierQuad(startPos, endPos, controlPos, 15.0f, MAROON);

        // 8.Draws a circle and fills it with two colors
        // DrawCircleGradient(500, 500, 50.0f, RED, YELLOW);

        // 9. Draws a circle without filling it with any color
        // DrawCircleLines(500, 500, 100, GOLD);

        //  Check Collision between two circles and change colour if they collide 
        mousePosition = GetMousePosition();

        if (CheckCollisionCircles(circlePosition, circleRadius, mousePosition, circleRadius))
        {
            circleColor = BLUE;
        }
        else
        {
            circleColor = RED;
        }

        DrawCircleV(circlePosition, circleRadius, circleColor);
        DrawCircleV(mousePosition, circleRadius, circleColor);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}