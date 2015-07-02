#include <iostream>

#include "game.h"
#include "display.h"
#include "prefabs.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// Instantiate Game
	Game game;

	// Load systems
	game.LoadDisplay("SDL2", 800, 600);
	game.LoadTimeController(60);
	game.LoadRenderer();

	// Load entities
	game.Instantiate<Player>();

	return 0;
}