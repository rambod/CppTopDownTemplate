//
// Created by rambod on 11/29/2023.
//
#include <iostream>
#include <raylib.h>

#ifndef CPPTOPDOWNTEMPLATE_CHARACTER_H
#define CPPTOPDOWNTEMPLATE_CHARACTER_H

class Character {
public:
    Character(int windowWidth, int windowHeight);
    Vector2 getWorldPos() { return worldPos; }
    void setWorldPos(Vector2 pos) { worldPos = pos; }
    void tick(float deltaTime);
    void undoMovement();
private:
    Texture2D texture{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("assets/characters/knight_run_spritesheet.png")};
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

#endif //CPPTOPDOWNTEMPLATE_CHARACTER_H
