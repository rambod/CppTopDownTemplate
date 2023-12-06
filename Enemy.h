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
    virtual void tick(float deltaTime) override;
    void setTarget(Character* character) { target = character; }
    virtual Vector2 getScreenPos() override;


private:
    Character* target;


};


#endif //CPPTOPDOWNTEMPLATE_ENEMY_H
