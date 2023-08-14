// Includes
#include <iostream>
using namespace ::std;

// Include files
#include "Texture2D.h"
#include "GameScreenLvl1.h"
#include "GameScreenMng.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "Collisions.h"

GameScreenLvl1::GameScreenLvl1(SDL_Renderer* renderer)
	: GameScreen(renderer)
{
	m_level_map = nullptr;
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

	if (Collision::Instance()->Circle(Mario, Luigi))
	{
		cout << "Circle hit" << endl;
	}
}

bool GameScreenLvl1::SetUpLevel()
{
	M_background_texture = new Texture2D(M_Renderer);
	if (!M_background_texture->LoadFromFile("Images/BackgroundMB.png"))
	{
		cout << "Failed to load background texture!" << endl;
			return false;
	}

	Mario = new CharacterMario(M_Renderer, "Images/Mario.png", Vector2D(64, 330), m_level_map);
	Luigi = new CharacterLuigi(M_Renderer, "Images/Luigi.png", Vector2D(128, 330), m_level_map);

	return true;
}

void GameScreenLvl1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, };

	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}

	m_level_map = new LevelMap(map);

}