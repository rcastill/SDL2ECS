System::System() : game(NULL)
{
}

void System::SetGame(Game *game)
{
	if (this->game == NULL)
		this->game = game;
}

bool System::Check()
{
	return setFailure;
}

string System::GetError()
{
	return failureDetail;
}

void System::PushError(string detail)
{
	setFailure = true
	failureDetail = detail;
}