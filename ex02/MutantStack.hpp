#pragma once
#include <stack>

template < typename T>
class MutantStack: public std::stack<T>
{
private:
	/* data */
public:
	MutantStack(/* args */);
	~MutantStack();


	class iterator
	{

	private:
		typename std::stack<T>::size_type _pos;

	public:

		iterator(typename std::stack<T>::size_type s): _pos(s) {};
		iterator(): _pos(-1) {};

		iterator operator++()
		{
			if (_pos < this->size())
				++_pos;
			else
				throw(std::exception());
			return(*this);
		};

		iterator operator--()
		{
			if (_pos > 0)
				--_pos;
			else
				throw(std::exception());
			return(*this);
		};

		bool operator==(iterator& other)
		{
			return (this->_pos == other.pos);
		}

		bool operator!=(iterator& other)
		{
			return (this->_pos != other.pos);
		}

		T& operator*()
		{
			return (this->top());
		}

	};

	iterator begin(){ return iterator(0); };
	iterator end()  { return iterator(this->size()); };
};

// template < typename T>
// MutantStack<T>::MutantStack::iterator operator++(MutantStack<T>::MutantStack::iterator it)
// {
// 	return(it);
// }


template < typename T>
MutantStack<T>::MutantStack(/* args */){};

template < typename T>
MutantStack<T>::~MutantStack(){};

