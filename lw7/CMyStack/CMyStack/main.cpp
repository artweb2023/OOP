#include "CMyStack.h"
#include <iostream>


int main()
{
	CMyStack<int> intStack;
	intStack.Push(1);
	intStack.Push(2);
	intStack.Push(3);

	while (!intStack.IsEmpty())
	{
		std::cout << "Top: " << intStack.Top() << std::endl;
		intStack.Pop();
	}

	CMyStack<std::string> stringStack;
	stringStack.Push("Hello");
	stringStack.Push("World");

	while (!stringStack.IsEmpty())
	{
		std::cout << "Top: " << stringStack.Top() << std::endl;
		stringStack.Pop();
	}

	return 0;
}