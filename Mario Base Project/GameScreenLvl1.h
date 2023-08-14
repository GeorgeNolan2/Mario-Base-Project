#pragma once

// Include files
#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"
#include "Character.h"
#include "LevelMap.h"

#ifndef _GAMESCREENLVL1_H
#define _GAMESCREENLVL1_H

class Texture2D;

class GameScreenLvl1 : public GameScreen
{

private:
	LevelMap* m_level_map;
	Texture2D* M_background_texture;
	Character* Mario;
	Character* Luigi;

public:
	GameScreenLvl1(SDL_Renderer* renderer);
	~GameScreenLvl1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e);

private:
	bool SetUpLevel();
	void SetLevelMap();
};

#endif _GAMESCREENLVL1_H
