#pragma once

// Include files
#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"
#include "Character.h"

#ifndef _GAMESCREENLVL1_H
#define _GAMESCREENLVL1_H

class Texture2D;

class GameScreenLvl1 : public GameScreen
{

private:
	Texture2D* M_background_texture;
	Character* my_character;

public:
	GameScreenLvl1(SDL_Renderer* renderer);
	~GameScreenLvl1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e);

private:
	bool SetUpLevel();
};

#endif _GAMESCREENLVL1_H
