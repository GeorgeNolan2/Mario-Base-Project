#pragma once

#ifndef _GAMESCREENMNG_H
#define _GAMESCREENMNG_H

//Include files
#include <SDL.h>
#include <string>
#include "Commons.h"
#include "GameScreen.h"

class GameScreenMng
{
public:
	GameScreenMng(SDL_Renderer* renderer, GameScreen* startScreen);
	~GameScreenMng();
	void Render();
	void Update(float deltaTime, SDL_Event& e);
	void ChangeScreens(Screens new_screen);

private:
	SDL_Renderer* renderer;
	GameScreen* current_screen;
};

#endif _GAMESCREENMNG_H