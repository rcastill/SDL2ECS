#include "prefabs.h"

Player::Player()
{
}

void Player::Init()
{
	AddComponent<WASDController>();
}