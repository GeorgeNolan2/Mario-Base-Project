#include "Character.h"
#include "Texture2D.h"

Character::Character(SDL_Renderer* Renderer, std::string imagePath, Vector2D start_position)
{
    M_Renderer = Renderer;
    M_Position = start_position;

    M_Texture = new Texture2D(M_Renderer);
    if (!M_Texture->LoadFromFile("Images/BackgroundMB.png"))
    {
        std::cout << "AMONG US";
    }
}

Character::~Character()
{
    // Destructor implementation
}

void Character::Render()
{
    // Render implementation
}

void Character::Update(float deltaTime, SDL_Event e)
{
    // Update implementation
}

void Character::SetPosition(Vector2D new_position)
{
    // SetPosition implementation
}

Vector2D Character::GetPosition()
{
    // GetPosition implementation
    return Vector2D(); // Return an appropriate Vector2D instance
}
