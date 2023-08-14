// Includes
#include <iostream>
using namespace ::std;

// Include files
#include "Texture2D.h"
#include "GameScreenLvl1.h"
#include "GameScreenMng.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"

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
	delete Mario;
	Mario = nullptr;
	delete Luigi;
	Luigi = nullptr;
}

void GameScreenLvl1::Render() 
{
	M_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	Mario->Render();
	Luigi->Render();
}

void GameScreenLvl1::Update(float deltaTime, SDL_Event e)
{
	Mario->Update(deltaTime, e);
	Luigi->Update(deltaTime, e);
}

bool GameScreenLvl1::SetUpLevel()
{
	M_background_texture = new Texture2D(M_Renderer);
	if (!M_background_texture->LoadFromFile("Images/BackgroundMB.png"))
	{
		cout << "Failed to load background texture!" << endl;
			return false;
	}

	Mario = new CharacterMario(M_Renderer, "Images/Mario.png", Vector2D(64, 330));
	Luigi = new CharacterLuigi(M_Renderer, "Images/Luigi.png", Vector2D(128, 330));
	return true;
}
