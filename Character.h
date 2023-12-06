//
// Created by rambod on 11/29/2023.
//


#ifndef CPPTOPDOWNTEMPLATE_CHARACTER_H
#define CPPTOPDOWNTEMPLATE_CHARACTER_H
#include <iostream>
#include <raylib.h>
#include "BaseCharacter.h"

class Character : public BaseCharacter {
public:
    Character(int winWidth, int winHeight);
    void setWorldPos(Vector2 pos) { worldPos = pos; }
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;

private:
    int windowWidth;
    int windowHeight;
    Texture2D weapon{LoadTexture("assets/characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{
    };
    float rotationAngleDeg = 0;
    float maxSpeed = 1.0f;
    float acceleration = 0.2f;

};

#endif //CPPTOPDOWNTEMPLATE_CHARACTER_H
