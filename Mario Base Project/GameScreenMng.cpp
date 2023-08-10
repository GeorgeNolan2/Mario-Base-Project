#include "GameScreenMng.h"
#include "GameScreen.h"
#include "GameScreenLvl1.h"

GameScreenMng::GameScreenMng(SDL_Renderer* renderer, GameScreen* startScreen)
{
	current_screen = nullptr;
    this->renderer = renderer;
	ChangeScreens(SCREEN_LEVEL1);
}

GameScreenMng::~GameScreenMng()
{
    if (current_screen != nullptr)
    {
        delete current_screen;
        current_screen = nullptr;
    }

    // Delete the renderer
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}

void GameScreenMng::Render()
{
    if (current_screen != nullptr)
    {
        current_screen->Render();
    }
}

void GameScreenMng::Update(float deltaTime, SDL_Event& e)
{
    current_screen -> Update();
}

void GameScreenMng::ChangeScreens(Screens new_screen)
{
    // Delete the previous screen if it exists
    if (current_screen != nullptr)
    {
        delete current_screen;
        current_screen = nullptr;
    }

    // Declare pointers to the new screens
    GameScreen* nextScreen = nullptr;
    GameScreenLvl1* screenLevel1 = nullptr;

    // Set up the new screen based on the screen enum passed in
    switch (new_screen)
    {
    case Screens::SCREEN_LEVEL1:
        // Create a new GameScreenLevel1 object and cast it to a GameScreen pointer
        screenLevel1 = new GameScreenLvl1(renderer);
        nextScreen = dynamic_cast<GameScreen*>(screenLevel1);
        break;

    default:
        // If an invalid screen enum was passed in, just set the next screen to nullptr
        nextScreen = nullptr;
        break;
    }

    // Set the current screen to the new screen
    current_screen = nextScreen;
}
