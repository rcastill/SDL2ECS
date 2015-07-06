#include "api/include/sdl2ecs.h"
#include "prefabs.hh"

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
    game.Instantiate<GlobalBehaviours>();

	// Run
	game.Start();

	return 0;
}
