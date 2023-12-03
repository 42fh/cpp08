#pragma once

template<typename T>
int* easyfind(T container, int n)
{
	for(typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == n)
			return &(*it);
	}
	// throw std::exception();
	// typename T::iterator it = container.begin();
	return NULL;
}