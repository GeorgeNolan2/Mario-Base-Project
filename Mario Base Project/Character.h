#pragma once

#include <iostream>
#include <SDL.h>
#include <string>
#include "Commons.h"

#ifndef Character

class Texture2D;

class Character
{
protected:
    SDL_Renderer* M_Renderer;
    Vector2D M_Position;
    Texture2D* M_Texture;

public:
    Character(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position);
    ~Character();
    virtual void Render();
    virtual void Update(float deltaTime, SDL_Event e);
    void SetPosition(Vector2D new_position);
    Vector2D GetPosition();
};

#endif Character