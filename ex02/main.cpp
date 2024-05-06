#include "MutantStack.hpp"
#include <iostream>

void pdffoo(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << "top = " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "size = "<< mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it;
	it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	std::cout << "size = "<< mstack.size() << std::endl;
	std::cout << "printing all of them" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

template <typename cont>
void mytests(void)
{
	cont s1;

	s1.push("hi");
	s1.push("there");
	s1.push("nice");
	s1.push("to");
	s1.push("meet");
	s1.push("you!");

	typename cont::iterator it;
	it = s1.begin();
	typename cont::iterator ite = s1.end();

	try
	{
		++it;
		--it;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	

	
	std::cout << "size = "<< s1.size() << std::endl;
	std::cout << "printing all of them" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}


int main()
{
	std::cout << "pdffoo" << std::endl;
	pdffoo();
	std::cout << "mytests< MutantStack<std::string> >" << std::endl;
	mytests< MutantStack<std::string> >();


	return 0;
}