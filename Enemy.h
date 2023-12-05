//
// Created by Rambod on 12/2/2023.
//

#ifndef CPPTOPDOWNTEMPLATE_ENEMY_H
#define CPPTOPDOWNTEMPLATE_ENEMY_H
#include "raylib.h"
#include "Character.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter {
public:
    Enemy(Vector2 pos,Texture2D idle_texture, Texture2D run_texture);
    void setWorldPos(Vector2 pos) { worldPos = pos; }
    void tick(float deltaTime);

private:


};


#endif //CPPTOPDOWNTEMPLATE_ENEMY_H
