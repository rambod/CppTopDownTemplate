#include <iostream>
#include <raylib.h>
#include <raygui.h>

int main() {

    InitWindow(800, 450, "raylib [core] example - basic window");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Congrats! You created your first window!", 190, 200, 20, WHITE);


        EndDrawing();

    }

    CloseWindow();

    return 0;
}
