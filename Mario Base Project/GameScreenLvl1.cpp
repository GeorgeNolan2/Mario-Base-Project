// Includes
#include <iostream>
using namespace ::std;

// Include files
#include "Texture2D.h"
#include "GameScreenLvl1.h"
#include "GameScreenMng.h"

GameScreenLvl1::GameScreenLvl1(SDL_Renderer* renderer)
	: GameScreen(renderer)
{
	M_background_texture = new Texture2D(renderer);
	SetUpLevel();
}

GameScreenLvl1::~GameScreenLvl1()
{
	delete M_background_texture;
	M_background_texture = nullptr;
}

void GameScreenLvl1::Render()
{
	M_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}

void GameScreenLvl1::Update(float deltaTime, SDL_Event e)
{
}

bool GameScreenLvl1::SetUpLevel()
{
	M_background_texture = new Texture2D(M_Renderer);
	if (!M_background_texture->LoadFromFile("Images/BackgroundMB.png"))
	{
		cout << "Failed to load background texture!" << endl;
			return false;
	}
	return true;
}
