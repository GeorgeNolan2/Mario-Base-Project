#pragma once
#include "CharacterMario.h"
#include "Texture2D.h"

CharacterMario::CharacterMario(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position, LevelMap* map)
    : Character(Renderer, imagePath, start_position, map) 
{
    M_Renderer = Renderer;
    M_Position = start_position;
    M_Texture = new Texture2D(M_Renderer);

    // Load the texture from the specified file
    if (!M_Texture->LoadFromFile(imagePath))
    {
        std::cout << "Failed to load texture from " << imagePath << std::endl;
        delete M_Texture;
        M_Texture = nullptr;
    }
}


CharacterMario::~CharacterMario() 
{

}

void CharacterMario::Render() 
{
    Character::Render();
}

void CharacterMario::Update(float deltaTime, SDL_Event e)
{
    Character::Update(deltaTime, e);

    // Handle the events
    switch (e.type)
    {
    case SDL_KEYDOWN: // Handle key press events
        switch (e.key.keysym.sym)
        {
        case SDLK_a:
            M_Moving_Left = true;
            break;
        case SDLK_d:
            M_Moving_Right = true;
            break;
        case SDLK_w:
            if (M_Can_Jump)
            {
                Jump();
            }
            break;
        }
        break;

    case SDL_KEYUP: // Handle key release events
        switch (e.key.keysym.sym)
        {
        case SDLK_a:
            M_Moving_Left = false;
            break;
        case SDLK_d:
            M_Moving_Right = false;
            break;
        }
        break;

    }
}
