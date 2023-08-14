#pragma once

#include <iostream>
#include <SDL.h>
#include <string>
#include "Commons.h"
#include "LevelMap.h"

#ifndef Character

class Texture2D;

class Character
{
protected:
    SDL_Renderer* M_Renderer;
    Vector2D M_Position;
    Texture2D* M_Texture;
    LevelMap* M_Current_Level_Map;
    bool M_Moving_Left;
    bool M_Moving_Right;
    bool M_Jumping;
    bool M_Can_Jump;
    float M_Jump_Force;
    float M_Collision_Radius;

private:
    FACING M_Facing_Direction;
    virtual void MoveLeft(float deltaTime);
    virtual void MoveRight(float deltaTime);
    virtual void Gravity(float deltaTime);

public:
    Character(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
    ~Character();
    virtual void Render();
    virtual void Update(float deltaTime, SDL_Event e);
    void SetPosition(Vector2D new_position);
    Vector2D GetPosition();
    virtual void Jump();
    float GetCollisionRadius();
};

#endif Character
