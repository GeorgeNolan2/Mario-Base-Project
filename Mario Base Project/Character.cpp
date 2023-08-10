#include "Character.h"
#include "Texture2D.h"

Character::Character(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position)
{
    M_Renderer = Renderer;
    M_Position = start_position;

    M_Texture = new Texture2D(M_Renderer);
    if (M_Texture->LoadFromFile("Images/BackgroundMB.png"))
    {
        std::cout << "AMONG US";
    }
}

Character::~Character()
{
    M_Renderer = nullptr;
}

void Character::Render()
{
    if (M_Texture != nullptr)
    {
        M_Texture->Render(M_Position, SDL_FLIP_NONE);
    }
}

void Character::Update(float deltaTime, SDL_Event e)
{
    // Get events
    SDL_PollEvent(&e);

    // Handle the events
    switch (e.type)
    {
    case SDLK_a:
        M_Position.x -= 1;
    case SDLK_d:
        M_Position.x += 1;
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
