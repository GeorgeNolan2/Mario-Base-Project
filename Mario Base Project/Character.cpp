#include "Character.h"
#include "Texture2D.h"
#include "Commons.h"
#include "Constants.h"

Character::Character(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position, LevelMap* map)
{
    M_Renderer = Renderer;
    M_Position = start_position;
    M_Facing_Direction = FACING_RIGHT;
    M_Texture = new Texture2D(M_Renderer);
    M_Current_Level_Map = map;
    M_Moving_Left = false;
    M_Moving_Right = false;
    M_Jumping = false;
    M_Can_Jump = true;
    M_Jump_Force = 0.0f;
    M_Collision_Radius = 15.0f;

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
}

void Character::Update(float deltaTime, SDL_Event e)
{
    if (M_Jumping)
    {
        M_Position.y -= M_Jump_Force * deltaTime;
        M_Jump_Force -= JUMP_FORCE_DECREMENT * deltaTime;

        if (M_Jump_Force <= 0.0f)
            M_Jumping = false;
    }

    if (M_Moving_Left)
    {
        MoveLeft(deltaTime);
    }
    else if (M_Moving_Right)
    {
        MoveRight(deltaTime);
    }

    Gravity(deltaTime);
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

void Character::MoveRight(float distance)
{
    M_Facing_Direction = FACING_RIGHT;
    M_Position.x += distance * MOVEMENTSPEED;
}

void Character::Gravity(float deltaTime)
{
    if(!M_Position.y + 64 <= Screen_Height)
    {
        M_Position.y += GRAVITY * deltaTime;
    }
    else
    {
        M_Can_Jump = true;
    }
}

float Character::GetCollisionRadius()
{
    return M_Collision_Radius;
}

void Character::Jump()
{
    M_Jump_Force = INITAL_JUMP_FORCE;
    M_Jumping = true;
    M_Can_Jump = false;
}