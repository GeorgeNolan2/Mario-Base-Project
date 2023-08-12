#pragma once

#include "Character.h"

#ifndef CHARACTER_LUIGI_H
#define CHARACTER_LUIGI_H

class CharacterLuigi : public Character {

public:
    CharacterLuigi(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position);
    ~CharacterLuigi();
    virtual void Render();
    virtual void Update(float deltaTime, SDL_Event e) override;
};

#endif // CHARACTER_LUIGI_H