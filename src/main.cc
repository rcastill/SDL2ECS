#include <iostream>

#include "sdl2ecs.h"
#include "prefabs.hh"

using namespace std;

int main(int argc, char const *argv[])
{
	// Instantiate Game
	Game game;

	// Load systems
	game.LoadDisplay("SDL2", 800, 600);
 
	game.LoadTimeController(60);
	game.LoadRenderer();
	game.LoadInput();

	// Load entities
	game.Instantiate<Player>();

	// Run
	game.Start();

	return 0;
}
