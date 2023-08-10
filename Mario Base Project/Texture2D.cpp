using namespace ::std;
#include <iostream>
#include <SDL_image.h>
#include "Texture2D.h"

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	M_Renderer = renderer;
	M_Texture = nullptr;
	M_Height = 0;
	M_Width = 0;
}

Texture2D::~Texture2D()
{
	M_Renderer = nullptr;
}


bool Texture2D::LoadFromFile(std::string path)
{
	Free();

	// Load the image
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface != nullptr)
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

		M_Texture = SDL_CreateTextureFromSurface(M_Renderer, surface);
		if (M_Texture == nullptr)
		{
			cout << " Unable to create texture from surface. Error: 1 " << SDL_GetError();
		}
		else
		{
			M_Height = surface->h;
			M_Width = surface->w;
		}

		SDL_FreeSurface(surface);
	}
	else
	{
		cout << "Failed to load image from path: " << path << ". Error: " << IMG_GetError() << endl;
		return false; // Return false to indicate failure
	}
	return M_Texture != nullptr;
}

void Texture2D::Free()
{
	if (M_Texture != nullptr)
	{
		SDL_DestroyTexture(M_Texture);
		M_Texture = nullptr;
		M_Height = 0;
		M_Width = 0;
	}
}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip)
{
	if (M_Renderer == nullptr)
	{
		cout << " M_Renderer is null, cannot create texture. Error 3" << endl;
	}

	if (M_Texture == nullptr)
	{
		cout << " Unable to create texture from surface. Error: 4 " << SDL_GetError();
	}

	if (M_Renderer != nullptr && M_Texture != nullptr)
	{
		// Set where to render the texture
		SDL_Rect M_RendererLocation = { 0, 0, M_Width, M_Height };

		// Render to the screen
		SDL_RenderCopyEx(M_Renderer, M_Texture, NULL, &M_RendererLocation, 0, NULL, SDL_FLIP_NONE);
	}
}