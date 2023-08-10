// Includes
#include <iostream>
using namespace ::std;

// Include files
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Constants.h"
#include "Texture2D.h"
#include "Commons.h"
#include "GameScreenMng.h"
 
// Globals
SDL_Window* G_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
GameScreenMng* g_screen_manager = nullptr;
Uint32 g_old_time;

// Bools and Voids
bool InitSDL();
void CloseSDL();
bool Update();
void Render();

// Main
int main(int argc, char* args[])
{
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cout << "SDL_image could not initialize PNG support. Error: " << IMG_GetError() << endl;
		return false; // Return an error code to indicate failure
	}

	// Check if SDL was set up correctly
	if (InitSDL())
	{
		g_screen_manager = new GameScreenMng(g_renderer, static_cast<GameScreen*>(nullptr));

		// set old time
		g_old_time = SDL_GetTicks();

		// Flags to check if we wish to quit
		bool quit = false;

		// Game loop
		while (!quit)
		{
			Render();
			quit = Update();
		}

	}

	CloseSDL();
	return 0;
}

// InitSDL
bool InitSDL()
{
	// Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. Error : 101";
		return false;
	}

	else
	{
		// Setup passed so create window
		G_window = SDL_CreateWindow("Games Engine Creation",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			Screen_Width,
			Screen_Height,
			SDL_WINDOW_SHOWN);

		g_renderer = SDL_CreateRenderer(G_window, -1, SDL_RENDERER_ACCELERATED);

		if (g_renderer != nullptr)
		{
			// Init PNG loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
				return false;
			}
		}

		else
		{
			cout << "Renderer could not initialise. Error: " << IMG_GetError();
			return false;
		}

		// Did the window get created?
		if (G_window == nullptr)
		{
			// Window failed
			cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}
	}
	return true;
}

void CloseSDL()
{
	// Destroy the game manager
	delete g_screen_manager;
	g_screen_manager = nullptr;

	// Release the window
	IMG_Quit();
	SDL_Quit();

	// Release the renderer
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;
}

bool Update()
{
	Uint32 new_time = SDL_GetTicks();

	// Event manager
	SDL_Event e;

	// Get events
	SDL_PollEvent(&e);

	// Handle the events
	switch (e.type)
	{
		// Click the 'X' to quit
	case SDL_QUIT:
			return true;
			break;
	}

	g_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, e);
	g_old_time = new_time;

	return false;

}

void Render()
{
	// Clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	// Update the screen
	g_screen_manager->Render();
	SDL_RenderPresent(g_renderer);
}