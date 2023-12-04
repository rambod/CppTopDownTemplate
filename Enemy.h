//
// Created by Rambod on 12/2/2023.
//

#ifndef CPPTOPDOWNTEMPLATE_ENEMY_H
#define CPPTOPDOWNTEMPLATE_ENEMY_H
#include "raylib.h"
#include "Character.h"


class Enemy {
public:
    Enemy(Vector2 pos,Texture2D idle_texture, Texture2D run_texture);
    Vector2 getWorldPos() { return worldPos; }
    void setWorldPos(Vector2 pos) { worldPos = pos; }
    void tick(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRec();
private:
    Texture2D texture{LoadTexture("assets/characters/goblin_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("assets/characters/goblin_idle_spritesheet.png")};
    Texture2D run{LoadTexture("assets/characters/goblin_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    float rotation = 0.0f;
    // 1. Facing right , -1. facing left
    float rightLeft{1.f};
    //animation variable
    int frame{};
    float runningTime = 0.0f;
    int maxFrames{6};
    float updateTime{1.f/12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{4.0f};

};


#endif //CPPTOPDOWNTEMPLATE_ENEMY_H
