//
// Created by rambo on 12/5/2023.
//

#include "BaseCharacter.h"
#include "iostream"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;


}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
            getScreenPos().x,
            getScreenPos().y,
            width * scale,
            height * scale
    };
}

void BaseCharacter::tick(float deltaTime) {
    worldPosLastFrame =worldPos;
    //update animation
    runningTime += deltaTime;
    if(runningTime >= updateTime){
        frame ++;
        runningTime = 0.0f;
        if(frame > maxFrames) frame = 0;
    }

    // update character position
    if(Vector2Length(velocity) != 0.0f){

        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));

        // Flip Texture
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;

    } else{
        texture = idle;
    }
    velocity = {};


    //draw the character
    Rectangle source{frame * width,0.f,rightLeft * (float)texture.width / 6.0f,height};
    Rectangle  dest{getScreenPos().x,getScreenPos().y,scale * width,scale * height};
    DrawTexturePro(texture,source,dest,Vector2{},0.f,WHITE);
}
