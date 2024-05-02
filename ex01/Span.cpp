#include "Span.hpp"

Span::Span(): maxNumberOfInts(0)
{
}

Span::~Span()
{
}

Span::Span(unsigned int N): maxNumberOfInts(N){
}

void Span::addNumber(int n){
	if (this->l1.size() < maxNumberOfInts)
	{
		l1.push_front(n);
	}
	else
	{
		throw std::exception();
	}
}


int Span::shortestSpan(){
	if (l1.size() < 2)
		throw std::exception();

	l1.sort();
	int shortest = l1.back() - l1.front();

	std::list<int>::iterator it = l1.begin();
	int previousNum = *it;
	++it;
	while (it != l1.end())
	{
		if (*it - previousNum < shortest)
			shortest = *it - previousNum;
		previousNum = *it;
		++it;
	}
	return (shortest);
}

unsigned int Span::longestSpan(){
	if (l1.size() < 2)
		throw std::exception();

	l1.sort();
	return(l1.back() - l1.front());
}
