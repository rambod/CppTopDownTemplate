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
    Character(int windowWidth, int windowHeight);
    void setWorldPos(Vector2 pos) { worldPos = pos; }
    void tick(float deltaTime);

private:

};

#endif //CPPTOPDOWNTEMPLATE_CHARACTER_H
