#include "wasdcontroller.h"

WASDController::WASDController() {}

bool WASDController::Init()
{
}

void WASDController::Update()
{
	Transform &transform = GetTransform();

	if (GetKeyPressed(SDLK_d))
		transform.x += 10;

	if (GetKeyPressed(SDLK_w))
		transform.y -= 10;

	if (GetKeyPressed(SDLK_a))
		transform.x -= 10;

	if (GetKeyPressed(SDLK_s))
		transform.y += 10;

	cout << transform << endl;
}