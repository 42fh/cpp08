#pragma once

#include <algorithm>

template <typename T>
int *easyfind(T container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return (&(*it));
	else
		return (NULL);
}


/*
 * simple for loop variant without <algo> header
 *

template <typename T>
int *easyfind(T container, int n)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == n)
			return &(*it);
	}
	return NULL;
}
*/