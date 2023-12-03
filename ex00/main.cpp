#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v(5, 99);
	std::cout << *easyfind(v, 99) << std::endl;
	std::cout << easyfind(v, 99) << std::endl;
	std::cout << easyfind(v, 939) << std::endl;

	std::deque<int> d;
	d.push_front(13);
	d.push_front(12);
	d.push_front(11);
	std::cout << *easyfind(d, 12) << std::endl;
	std::cout << easyfind(d, 12) << std::endl;
	std::cout << easyfind(d, 939) << std::endl;
	return 0;
}
