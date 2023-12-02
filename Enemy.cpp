//
// Created by Rambod on 12/2/2023.
//

#include "Enemy.h"


Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) :
    worldPos(pos), texture(idle_texture), idle(idle_texture),run(run_texture)
{

}