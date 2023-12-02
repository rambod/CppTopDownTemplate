//
// Created by rambod on 12/1/2023.
//

#ifndef CPPTOPDOWNTEMPLATE_PROP_H
#define CPPTOPDOWNTEMPLATE_PROP_H

#include <raylib.h>


class Prop {
public:
    Prop(Vector2 pos,Texture2D tex);
    void Render(Vector2 playerPos);
    Rectangle getCollisionRec(Vector2 playerPos);
private:
    Texture2D texture{};
    Vector2 worldPos{};
    float scale{4.f};

};


#endif //CPPTOPDOWNTEMPLATE_PROP_H
