#pragma once
#include <stack>

#define NULL 0

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
		typename std::stack<T>::size_type	_pos;
		MutantStack<T>*						_stack;

	public:

		iterator(): _pos(0), _stack(NULL) {};
		iterator(typename std::stack<T>::size_type s): _pos(s), _stack(NULL) {};
		iterator(MutantStack<T>* ptr): _pos(0), _stack(ptr) {};
		iterator(typename std::stack<T>::size_type s, MutantStack<T>* ptr): _pos(s), _stack(ptr) {};

		iterator operator++()
		{
			if (_pos < _stack->size())
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

		bool operator!=(iterator& other)
		{
			return (this->_pos != other._pos);
		}

		T& operator*()
		{
			MutantStack<T> tmp;

			for (std::size_t i = 0; i < _pos; i++)
			{
				T tmpval = _stack->top();
				_stack->pop();
				tmp.push(tmpval);
			}
			
			T& ref = _stack->top();
			
			for (std::size_t i = 0; i < _pos; i++)
			{
				T tmpval = tmp.top();
				tmp.pop();
				_stack->push(tmpval);
			}
			
			return (ref);
		}

	};

	iterator it;

	iterator begin(){ return iterator(0, this); 			};
	iterator end()  { return iterator(this->size(), this);	};
};



template < typename T>
MutantStack<T>::MutantStack(/* args */): it(this){};

template < typename T>
MutantStack<T>::~MutantStack(){};

