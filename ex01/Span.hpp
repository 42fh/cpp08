#pragma once

#include <list>
#include <iostream>

class Span
{
private:
	unsigned int	maxNumberOfInts;
	std::list<int>	l1;
public:
	Span();
	Span(unsigned int N);
	~Span();
	void addNumber(int n);

	template <typename C>
	void addMultipleNumbers(typename C::iterator begin, typename C::iterator end)
	{
		typename C::iterator it = begin;
		while (it != end)
		{
			this->addNumber(*it);
			it++;
		}
	};

	int shortestSpan();
	unsigned int longestSpan();
};


// template <typename C>
// void Span::addMultipleNumbers(typename C::iterator begin, typename C::iterator end)
// {
// 	typename C::iterator it = begin;
// 	while (it != end)
// 	{
// 		this->addNumber(*it);
// 		it++;
// 	}
	
// }