#include "CStringStack.h"
#include <iostream>

int main()
{
	std::string line;
	CStringStack stack1;
	while (std::getline(std::cin, line))
	{
		stack1.Push(line);
	}
	CStringStack stack2(stack1);
	if (!stack2.IsEmpty())
	{
		stack2.Pop();
	}
	std::cout << stack2.GetSize() << std::endl;
}

