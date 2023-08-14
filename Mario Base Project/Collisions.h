#pragma once

#include "Character.h"
#include "Commons.h"

#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
private:
    Collision();
    static Collision* M_Instance;

public:
    ~Collision();
    static Collision* Instance();
    bool Circle(Character* Mario, Character* Luigi);
    bool Box(Rect2D rect1, Rect2D rect2);
};

#endif // COLLISION_H
