#pragma once

#include "Character.h"

#ifndef CHARACTER_MARIO_H
#define CHARACTER_MARIO_H

class CharacterMario : public Character {

public:
    CharacterMario(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position);
    ~CharacterMario();
    virtual void Render();
    virtual void Update(float deltaTime, SDL_Event e) override;
};

#endif // CHARACTER_MARIO_H
