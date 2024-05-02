#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int main()
{
	
	std::cout << "find numbers in the vector [99, 99, 99, 99, 99]" << std::endl;
	std::vector<int> v(5, 99);
	std::cout << *easyfind(v, 99) << std::endl;
	std::cout << easyfind(v, 99) << std::endl;
	std::cout << easyfind(v, 17) << std::endl;

	std::cout << "\n\n" "find numbers in the deque [11, 12, 13]" << std::endl;
	std::deque<int> d;
	d.push_front(13);
	d.push_front(12);
	d.push_front(11);
	std::cout << *easyfind(d, 12) << std::endl;
	std::cout << easyfind(d, 12) << std::endl;
	std::cout << easyfind(d, 80) << std::endl;
	return 0;
}
