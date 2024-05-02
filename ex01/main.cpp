#include <iostream>
#include <vector>
#include <cstdlib>
	

#include "Span.hpp"

#define CONT_SIZE 100000

template <typename C>
C rand_cont(size_t N)
{
	std::srand(time(NULL));
	C cont;

	for (size_t i = 0; i < N; i++)
	{
		cont.push_back(std::rand());
	}
	return(cont);
}

template <typename C>
void putcont(C con, int max = 0)
{
	if (max == 0)
	{
		for (typename C::iterator it = con.begin(); it != con.end(); ++it)
		{
			std::cout << *it << ", ";
		}
	}
	else
	{
		for (typename C::iterator it = con.begin(); it != con.end() && --max; ++it)
		{
			std::cout << *it << ", ";
		}
		std::cout << "..., " << *(con.end()) << "\n";
	}
}



int main()
{
	// PDF example
	{	
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	// Throw excepton for span of size 1 
	{	
		Span tiny = Span(1);
		tiny.addNumber(6);
		try
		{
			std::cout << tiny.shortestSpan() << std::endl;
		}
		catch(const std::exception& e){ std::cerr << "caught shortestSpan: " << e.what() << '\n'; }
		
		try
		{
			std::cout << tiny.longestSpan() << std::endl;
		}
		catch(const std::exception& e){ std::cerr << "caught longestSpan: " << e.what() << '\n'; }

	}

	// big span
	{
		std::vector<int> v = rand_cont<std::vector<int> >(CONT_SIZE);
		putcont(v, 20); // prints at most 20 elements
		Span big(CONT_SIZE);
		big.addMultipleNumbers<std::vector<int> >(v.begin(), v.end());
		std::cout << big.shortestSpan() << std::endl;
		std::cout << big.longestSpan() << std::endl;
	}

	return 0;
}