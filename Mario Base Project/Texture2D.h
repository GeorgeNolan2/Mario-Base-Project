#pragma once

#include <SDL.h>
#include <string>
#include "Commons.h"

#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H

class Texture2D
{

public:

	Texture2D(SDL_Renderer* renderer);
	~Texture2D();

	bool LoadFromFile(std::string path);
	void Free();
	void Render(Vector2D new_position, SDL_RendererFlip flip);

private:

	SDL_Renderer* M_Renderer;
	SDL_Texture* M_Texture;
	int M_Width;
	int M_Height;

};

#endif _TEXTURE2D_H
