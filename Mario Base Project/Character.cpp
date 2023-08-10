#include "Character.h"
#include "Texture2D.h"
#include "Commons.h"
#include "Constants.h"

Character::Character(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position)
{
    M_Renderer = Renderer;
    M_Position = start_position;
    M_Facing_Direction = FACING_RIGHT;
    M_Texture = new Texture2D(M_Renderer);
    M_Moving_Left = false;
    M_Moving_Right = false;

    // Load the texture from the specified file
    if (!M_Texture->LoadFromFile(imagePath))
    {
        std::cout << "Failed to load texture from " << imagePath << std::endl;
        delete M_Texture;
        M_Texture = nullptr;
    }
}

Character::~Character()
{
    M_Renderer = nullptr;
}

void Character::Render()
{
    if (M_Facing_Direction == FACING_RIGHT)
    {
        M_Texture->Render(M_Position, SDL_FLIP_NONE);
    }
    else
    {
        M_Texture->Render(M_Position, SDL_FLIP_HORIZONTAL);
    }

    if (M_Texture != nullptr)
    {
        M_Texture->Render(M_Position, SDL_FLIP_NONE);
    }
}

void Character::Update(float deltaTime, SDL_Event e)
{
    if (M_Moving_Left)
    {
        MoveLeft(deltaTime);
    }
    else if (M_Moving_Right)
    {
        MoveRight(deltaTime);
    }

    // Handle the events
    switch (e.type)
    {
    case SDL_KEYDOWN: // Handle key press events
        switch (e.key.keysym.sym)
        {
        case SDLK_a:
            M_Moving_Left = true;
            std::cout << "Key A pressed (move left)" << std::endl;
            break;
        case SDLK_d:
            M_Moving_Right = true;
            std::cout << "Key D pressed (move right)" << std::endl;
            break;
        }
        break;

    case SDL_KEYUP: // Handle key release events
        switch (e.key.keysym.sym)
        {
        case SDLK_a:
            M_Moving_Left = false;
            std::cout << "Key A released" << std::endl;
            break;
        case SDLK_d:
            M_Moving_Right = false;
            std::cout << "Key D released" << std::endl;
            break;
        }
        break;
    }

}

void Character::SetPosition(Vector2D new_position)
{
    M_Position = new_position;
}

Vector2D Character::GetPosition()
{
    return M_Position;
}

void Character::MoveLeft(float distance)
{
    M_Facing_Direction = FACING_LEFT;
    M_Position.x -= distance * MOVEMENTSPEED;
}

// Move right function
void Character::MoveRight(float distance)
{
    M_Facing_Direction = FACING_RIGHT;
    M_Position.x += distance * MOVEMENTSPEED;
}