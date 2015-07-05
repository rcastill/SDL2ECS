template <typename T>
void Component::Instantiate()
{
	assert(game != NULL);
	game->Instantiate<T>();
}

template <typename T>
T *Component::AddComponent()
{
	assert(entity != NULL);
	return entity->AddComponent<T>();
}

template <typename Derived>
Derived *Component::GetComponent()
{
	assert(entity != NULL);
	return entity->GetComponent<Derived>();
}


