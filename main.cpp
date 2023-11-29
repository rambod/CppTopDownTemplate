#include <iostream>
#include <raylib.h>
#include <raygui.h>
#include <raymath.h>


class Character {
public:
    Vector2 GetWorldPos() { return worldPos; }
    void SetScreenPos(int winWidth,int winHeight);
    void SetWorldPos(Vector2 pos) { worldPos = pos; }
    void tick(float deltaTime);
private:
    Texture2D texture{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("assets/characters/knight_run_spritesheet.png")};
    Vector2 screenPos;
    Vector2 worldPos;
    float rotation = 0.0f;
    // 1. Facing right , -1. facing left
    float rightLeft{1.f};
    //animation variable
    int frame{};
    float runningTime = 0.0f;
    const int maxFrames{6};
    const float updateTime{1.f/12.f};
    const float speed{4.f};

};

void Character::SetScreenPos(int winWidth,int winHeight) {
    screenPos =  {(float)winWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),(float)winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
}

void Character::tick(float deltaTime) {

    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if(IsKeyDown(KEY_D))
        direction.x += 1.0;
    if(IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if(IsKeyDown(KEY_S))
        direction.y += 1.0;

    if(Vector2Length(direction) != 0.0f){

        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));

        // Flip Texture
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;

    } else{
        texture = idle;
    }
    runningTime += deltaTime;
    if(runningTime >= updateTime){
        frame ++;
        runningTime = 0.0f;
        if(frame > maxFrames) frame = 0;
    }

}


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

    Texture2D  knight = LoadTexture("assets/characters/knight_idle_spritesheet.png");
    Vector2 knightPos{(float)gameSettings.width / 2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),(float)gameSettings.height / 2.0f - 4.0f * (0.5f * (float)knight.height)};

    Texture2D knight_idle = LoadTexture("assets/characters/knight_idle_spritesheet.png");
//    Vector2 knight_idlePos{(float)gameSettings.width / 2.0f - 4.0f * (0.5f * (float)knight_idle.width / 6.0f),(float)gameSettings.height / 2.0f - 4.0f * (0.5f * (float)knight_idle.height)};

    Texture2D knight_run = LoadTexture("assets/characters/knight_run_spritesheet.png");
//    Vector2 knight_runPos{(float)gameSettings.width / 2.0f - 4.0f * (0.5f * (float)knight_run.width / 6.0f),(float)gameSettings.height / 2.0f - 4.0f * (0.5f * (float)knight_run.height)};

    // 1. Facing right , -1. facing left
    float rightLeft{1.f};

    //animation variable
    int frame = 0;
    float runningTime = 0.0f;
    const int maxFrames{6};
    const float updateTime{1.f/12.f};


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

        if(Vector2Length(direction) != 0.0f){

            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));

            // Flip Texture
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            knight = knight_run;

        } else{
            knight = knight_idle;
        }

        // Draw Map
        DrawTextureEx(
                mapTexture2D,
                mapPos,
                0.0f,
                4.0f,
                WHITE
        );
        //update animation frame
        runningTime += GetFrameTime();
        if(runningTime >= updateTime){
            frame ++;
            runningTime = 0.0f;
            if(frame > maxFrames) frame = 0;
        }

        //draw the character
        Rectangle source{frame * (float)knight.width / 6.0f,0.f,rightLeft * (float)knight.width / 6.0f,(float)knight.height};
        Rectangle  dest{knightPos.x,knightPos.y,4.0f*(float)knight.width / 6.0f,4.0f * (float)knight.height};

        DrawTexturePro(knight,source,dest,Vector2{},0.f,WHITE);

        // End Drawing
        EndDrawing();

    }

    // Unload Texture
    UnloadTexture(mapTexture2D);

    CloseWindow();

    return 0;
}
