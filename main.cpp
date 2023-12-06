#include <iostream>
#include <raylib.h>
#include <raygui.h>
#include <raymath.h>
#include "Character.h"
#include "Prop.h"
#include "string"
#include "Enemy.h"

struct GameSettings {
    int width;
    int height;
};

int main() {
    GameSettings gameSettings = {
        .width = 1024,
        .height = 860
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
    Enemy goblin{Vector2 (500.0f,900.0f),
                LoadTexture("assets/characters/goblin_idle_spritesheet.png"),
                LoadTexture("assets/characters/goblin_run_spritesheet.png"),
    };
    Enemy slime{Vector2 (500.0f,500.0f),
                 LoadTexture("assets/characters/slime_idle_spritesheet.png"),
                 LoadTexture("assets/characters/slime_run_spritesheet.png"),
    };
    Enemy goblin2{Vector2 (500.0f,800.0f),
                 LoadTexture("assets/characters/goblin_idle_spritesheet.png"),
                 LoadTexture("assets/characters/goblin_run_spritesheet.png"),
    };


    // Create an array of Enemy* called enemies
    Enemy* enemies[] = {&goblin, &slime, &goblin2};

    for(Enemy* enemy : enemies){
        enemy->setTarget(&player);
    }

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

        if(!player.getAlive()){
            DrawText("Game Over", 20, 20, 20, RED);
            EndDrawing();
            continue;
        } else{
            std::string  playerHealth = "Health: ";
            playerHealth.append(std::to_string(player.getHealth()), 0,3);
            DrawText(playerHealth.c_str(), 30.0, 30.0, 40, RED);
        }

        //update animation frame
        player.tick(GetFrameTime());

        //Check if player is out of bounds
        if(player.getWorldPos().x <0.f || player.getWorldPos().y < 0.0f || player.getWorldPos().x + gameSettings.width >  mapTexture2D.width * mapScale || player.getWorldPos().y + gameSettings.height > mapTexture2D.height * mapScale){
            player.undoMovement();
            printf("out of boundry");
        }

        //Check for collision
        for(auto prop : props){
            if(CheckCollisionRecs(player.getCollisionRec(), prop.getCollisionRec(player.getWorldPos()))){
                player.undoMovement();
            }
        }
        for(Enemy* enemy : enemies){
            enemy->tick(GetFrameTime());
        }
//        goblin.tick(GetFrameTime());


        std::string worldPosText = std::to_string(player.getWorldPos().x) + ", " + std::to_string(player.getWorldPos().y);
        DrawText(worldPosText.c_str(), 20, gameSettings.height - 50, 20, BLACK);

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            for(Enemy* enemy : enemies){
                if( CheckCollisionRecs(enemy->getCollisionRec(), player.getWeaponCollisionRec())) {

                    enemy->setAlive(false);
                }
            }


        }

        // End Drawing
        EndDrawing();

    }
    // Unload Texture
    UnloadTexture(mapTexture2D);

    CloseWindow();

    return 0;
}
