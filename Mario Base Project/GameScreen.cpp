//Includes
#include <iostream>
using namespace :: std;

#include "GameScreen.h"
#include "GameScreenMng.h"
#include "Texture2D.h"

GameScreen::GameScreen(SDL_Renderer* renderer)
	:M_Renderer(renderer)
{
}

GameScreen::~GameScreen()
{
	M_Renderer = nullptr;
}

void GameScreen::Render()
{
}

void GameScreen::Update()
{
}
