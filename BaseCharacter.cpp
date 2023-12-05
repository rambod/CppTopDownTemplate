//
// Created by rambo on 12/5/2023.
//

#include "BaseCharacter.h"

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
            screenPos.x,
            screenPos.y,
            width * scale,
            height * scale
    };
}
