#include <iostream>
#include <raylib.h>
#include <raygui.h>
#include <raymath.h>
#include "Character.h"
#include "Prop.h"
#include "string"

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
    const float mapScale = 4.0f;

    //Character
    Character player{gameSettings.width ,gameSettings.height};

    Prop props[2]{
        Prop{Vector2{600.0f,600.0f}, LoadTexture("assets/nature_tileset/Rock.png")},
        Prop{Vector2{300.0f,600.0f}, LoadTexture("assets/nature_tileset/Log.png")}
    };

    SetTargetFPS(60);

    // draw text player world postion


    while (!WindowShouldClose()) {
        UpdateMusicStream(music);
        // Begin Drawing
        BeginDrawing();
        // Clear Screen
        ClearBackground(WHITE);
        mapPos = Vector2Scale(player.getWorldPos(), -1.0f);
        // Draw Map
        DrawTextureEx(
                mapTexture2D,
                mapPos,
                0.0f,
                mapScale,
                WHITE
        );


        // Draw Props
        for(auto prop : props){
            prop.Render(player.getWorldPos());
        }

        //update animation frame
        player.tick(GetFrameTime());

        //Check if player is out of bounds
        if(player.getWorldPos().x <0.f || player.getWorldPos().y < 0.0f || player.getWorldPos().x + gameSettings.width >  mapTexture2D.width * mapScale || player.getWorldPos().y + gameSettings.height > mapTexture2D.height * mapScale){
            player.undoMovement();
        }

        //Check for collision
        for(auto prop : props){
            if(CheckCollisionRecs(player.getCollisionRec(), prop.getCollisionRec(player.getWorldPos()))){
                player.undoMovement();
            }
        }


        std::string worldPosText = std::to_string(player.getWorldPos().x) + ", " + std::to_string(player.getWorldPos().y);
        DrawText(worldPosText.c_str(), 20, 20, 20, BLACK);

        // End Drawing
        EndDrawing();

    }
    // Unload Texture
    UnloadTexture(mapTexture2D);

    CloseWindow();

    return 0;
}
