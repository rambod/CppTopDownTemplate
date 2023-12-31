//
// Created by rambo on 12/5/2023.
//

#ifndef CPPTOPDOWNTEMPLATE_BASECHARACTER_H
#define CPPTOPDOWNTEMPLATE_BASECHARACTER_H

#include "raylib.h"

class BaseCharacter {
public:
    BaseCharacter();
    virtual ~BaseCharacter() = default;
    Vector2 getWorldPos() { return worldPos; }
    virtual void tick(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRec();
    virtual Vector2 getScreenPos() = 0;
    bool getAlive(){return alive;}
    void setAlive(bool alive){this->alive = alive;}
protected:
    Texture2D texture{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("assets/characters/knight_run_spritesheet.png")};
//    Vector2 screenPos{};
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
    Vector2 velocity{};
private:
    bool alive{true};

};


#endif //CPPTOPDOWNTEMPLATE_BASECHARACTER_H
