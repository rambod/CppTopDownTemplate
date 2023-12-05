//
// Created by Rambod on 12/2/2023.
//

#include "Enemy.h"


Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
}

void Enemy::tick(float deltaTime) {
    worldPosLastFrame =worldPos;


    //update animation
    runningTime += deltaTime;
    if(runningTime >= updateTime){
        frame ++;
        runningTime = 0.0f;
        if(frame > maxFrames) frame = 0;
    }
    //draw the character
    Rectangle source{frame * width,0.f,rightLeft * (float)texture.width / 6.0f,height};
    Rectangle  dest{screenPos.x,screenPos.y,scale * width,scale * height};

    DrawTexturePro(texture,source,dest,Vector2{},0.f,WHITE);

}

