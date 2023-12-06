//
// Created by Rambod on 12/2/2023.
//

#include "Enemy.h"
#include "raymath.h"


Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.0f;
}

void Enemy::tick(float deltaTime) {
    // get toTarget
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    BaseCharacter::tick(deltaTime);

}

Vector2 Enemy::getScreenPos() {
    return Vector2{ Vector2Subtract(worldPos, target->getWorldPos())};
}

