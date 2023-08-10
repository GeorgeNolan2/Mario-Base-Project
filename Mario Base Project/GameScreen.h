#pragma once

// Include files
#include <SDL.h>
#include "Commons.h"

#ifndef _GameScreen_h
#define _GameScreen_h

class GameScreen
{
public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

protected:
	SDL_Renderer* M_Renderer;

};
#endif _GameScreen_h