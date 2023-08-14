#pragma once
#include "CharacterLuigi.h"
#include "Texture2D.h"

CharacterLuigi::CharacterLuigi(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position)
    : Character(Renderer, imagePath, start_position)
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


CharacterLuigi::~CharacterLuigi()
{

}

void CharacterLuigi::Render()
{
    Character::Render();
}

void CharacterLuigi::Update(float deltaTime, SDL_Event e)
{
    Character::Update(deltaTime, e);

    // Handle the events
    switch (e.type)
    {
    case SDL_KEYDOWN: // Handle key press events
        switch (e.key.keysym.sym)
        {
        case SDLK_j:
            M_Moving_Left = true;
            break;
        case SDLK_l:
            M_Moving_Right = true;
            break;
        case SDLK_i:
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
        case SDLK_l:
            M_Moving_Left = false;
            break;
        case SDLK_j:
            M_Moving_Right = false;
            break;
        }
        break;
    }
}
