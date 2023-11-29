#include <iostream>
#include <raylib.h>
#include <raygui.h>
#include <raymath.h>

struct GameSettings {
    int width;
    int height;
};

int main() {
    GameSettings gameSettings = {
        .width = 384,
        .height = 384
    };
    InitWindow(gameSettings.width, gameSettings.height, "CppTopDownTemplate");

    // Texture Paths
    const char* mapTexture = "assets/DemoMap.png";


    //Audio Device
    InitAudioDevice();

    //Load Music and Sounds
    Music music = LoadMusicStream("assets/Sounds/the-white-lion.mp3");
    //Play Music
    PlayMusicStream(music);

    // Tilemap Settings
    Texture2D mapTexture2D = LoadTexture(mapTexture);
    Vector2 mapPos{0.0f,0.0f};
    float speed = 4.0f;



    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateMusicStream(music);

        // Begin Drawing
        BeginDrawing();

        // Clear Screen
        ClearBackground(WHITE);
        Vector2 direction{};
        if (IsKeyDown(KEY_A))
            direction.x -= 1.0;
        if(IsKeyDown(KEY_D))
            direction.x += 1.0;
        if(IsKeyDown(KEY_W))
            direction.y -= 1.0;
        if(IsKeyDown(KEY_S))
            direction.y += 1.0;

        if(Vector2Length(direction) > 0.0f){

            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }



        // Draw Map
        DrawTextureEx(
                mapTexture2D,
                mapPos,
                0.0f,
                4.0f,
                WHITE
        );




        // End Drawing
        EndDrawing();

    }

    // Unload Texture
    UnloadTexture(mapTexture2D);

    CloseWindow();

    return 0;
}
