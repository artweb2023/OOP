#define CATCH_CONFIG_MAIN
#include "../CMyStack/CMyStack.h"
#include "/OOP/catch2/catch.hpp"

SCENARIO("Testing string CMyStack")
{
	GIVEN("An empty CMyStack")
	{
		CMyStack<std::string> stack;
		THEN("The initial size should be 0")
		{
			REQUIRE(stack.GetSize() == 0);
			REQUIRE(stack.IsEmpty());
		}
		WHEN("A string is pushed onto the stack")
		{
			std::string str = "test";
			stack.Push(str);

			THEN("The size should be 1 and the top element should be the pushed string")
			{
				REQUIRE(stack.GetSize() == 1);
				REQUIRE_FALSE(stack.IsEmpty());
				REQUIRE(stack.Top() == str);
			}
		}
		WHEN("Multiple strings are pushed onto the stack")
		{
			stack.Push("first");
			stack.Push("second");
			stack.Push("third");
			THEN("The size should be 3 and the top element should be the last pushed string")
			{
				REQUIRE(stack.GetSize() == 3);
				REQUIRE(stack.Top() == "third");
			}
		}
		WHEN("A string is popped from the stack")
		{
			stack.Push("only");
			stack.Pop();

			THEN("The size should be 0 and the stack should be empty")
			{
				REQUIRE(stack.GetSize() == 0);
				REQUIRE(stack.IsEmpty());
			}
		}
		WHEN("Attempting to pop from an empty stack")
		{
			THEN("An exception should be thrown")
			{
				REQUIRE_THROWS_AS(stack.Pop(), std::out_of_range);
			}
		}
		WHEN("Attempting to get the top element from an empty stack")
		{
			THEN("An exception should be thrown")
			{
				REQUIRE_THROWS_AS(stack.Top(), std::out_of_range);
			}
		}
		WHEN("The stack is copied")
		{
			stack.Push("original");
			CMyStack<std::string> copiedStack = stack;
			THEN("The copied stack should have the same elements as the original")
			{
				REQUIRE(copiedStack.GetSize() == stack.GetSize());
				REQUIRE(copiedStack.Top() == stack.Top());
			}
		}
		WHEN("The stack is moved")
		{
			stack.Push("original");
			CMyStack<std::string> movedStack = std::move(stack);
			THEN("The moved stack should have the original elements and the original should be empty")
			{
				REQUIRE(movedStack.GetSize() == 1);
				REQUIRE(movedStack.Top() == "original");
				REQUIRE(stack.GetSize() == 0);
				REQUIRE(stack.IsEmpty());
			}
		}
		WHEN("Assigning one stack to another using copy assignment")
		{
			CMyStack<std::string> stack1;
			stack1.Push("one");
			stack1.Push("two");
			CMyStack<std::string> stack2;
			stack2.Push("alpha");
			stack2.Push("beta");
			stack2 = stack1;
			THEN("The assigned stack should have the same elements as the source stack")
			{
				REQUIRE(stack2.GetSize() == stack1.GetSize());
				REQUIRE(stack2.Top() == stack1.Top());
				stack2.Pop();
				stack1.Pop();
				REQUIRE(stack2.Top() == stack1.Top());
			}
		}
		WHEN("Assigning one stack to another using move assignment")
		{
			CMyStack<std::string> stack1;
			stack1.Push("one");
			stack1.Push("two");
			CMyStack<std::string> stack2;
			stack2 = std::move(stack1);
			THEN("The moved-to stack should have the original elements and the original should be empty")
			{
				REQUIRE(stack2.GetSize() == 2);
				REQUIRE(stack2.Top() == "two");
				stack2.Pop();
				REQUIRE(stack2.Top() == "one");
				REQUIRE(stack1.GetSize() == 0);
				REQUIRE(stack1.IsEmpty());
			}
		}
		WHEN("Assigning self-copying stack")
		{
			CMyStack<std::string> stack1;
			stack1.Push("one");
			stack1 = stack1;
			THEN("The stack should have the original elements")
			{
				REQUIRE(stack1.Top() == "one");
				REQUIRE(stack1.GetSize() == 1);
			}
		}
	}
}

SCENARIO("Testing int CMyStack")
{
	GIVEN("An empty CMyStack")
	{
		CMyStack<int> stack;
		THEN("The initial size should be 0")
		{
			REQUIRE(stack.GetSize() == 0);
			REQUIRE(stack.IsEmpty());
		}
		WHEN("A string is pushed onto the stack")
		{
			stack.Push(1);

			THEN("The size should be 1 and the top element should be the pushed int")
			{
				REQUIRE(stack.GetSize() == 1);
				REQUIRE_FALSE(stack.IsEmpty());
				REQUIRE(stack.Top() == 1);
			}
		}
		WHEN("Multiple int are pushed onto the stack")
		{
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			THEN("The size should be 3 and the top element should be the last pushed int")
			{
				REQUIRE(stack.GetSize() == 3);
				REQUIRE(stack.Top() == 3);
			}
		}
		WHEN("A string is popped from the stack")
		{
			stack.Push(1);
			stack.Pop();

			THEN("The size should be 0 and the stack should be empty")
			{
				REQUIRE(stack.GetSize() == 0);
				REQUIRE(stack.IsEmpty());
			}
		}
		WHEN("Attempting to pop from an empty stack")
		{
			THEN("An exception should be thrown")
			{
				REQUIRE_THROWS_AS(stack.Pop(), std::out_of_range);
			}
		}
		WHEN("Attempting to get the top element from an empty stack")
		{
			THEN("An exception should be thrown")
			{
				REQUIRE_THROWS_AS(stack.Top(), std::out_of_range);
			}
		}
		WHEN("The stack is copied")
		{
			stack.Push(12);
			CMyStack<int> copiedStack = stack;
			THEN("The copied stack should have the same elements as the original")
			{
				REQUIRE(copiedStack.GetSize() == stack.GetSize());
				REQUIRE(copiedStack.Top() == stack.Top());
			}
		}
		WHEN("The stack is moved")
		{
			stack.Push(15);
			CMyStack<int> movedStack = std::move(stack);
			THEN("The moved stack should have the original elements and the original should be empty")
			{
				REQUIRE(movedStack.GetSize() == 1);
				REQUIRE(movedStack.Top() == 15);
				REQUIRE(stack.GetSize() == 0);
				REQUIRE(stack.IsEmpty());
			}
		}
		WHEN("Assigning one stack to another using copy assignment")
		{
			CMyStack<int> stack1;
			stack1.Push(1);
			stack1.Push(2);
			CMyStack<int> stack2;
			stack2.Push(3);
			stack2.Push(4);
			stack2 = stack1;
			THEN("The assigned stack should have the same elements as the source stack")
			{
				REQUIRE(stack2.GetSize() == stack1.GetSize());
				REQUIRE(stack2.Top() == stack1.Top());
				stack2.Pop();
				stack1.Pop();
				REQUIRE(stack2.Top() == stack1.Top());
			}
		}
		WHEN("Assigning one stack to another using move assignment")
		{
			CMyStack<int> stack1;
			stack1.Push(1);
			stack1.Push(2);
			CMyStack<int> stack2;
			stack2 = std::move(stack1);
			THEN("The moved-to stack should have the original elements and the original should be empty")
			{
				REQUIRE(stack2.GetSize() == 2);
				REQUIRE(stack2.Top() == 2);
				stack2.Pop();
				REQUIRE(stack2.Top() == 1);
				REQUIRE(stack1.GetSize() == 0);
				REQUIRE(stack1.IsEmpty());
			}
		}
		WHEN("Assigning self-copying stack")
		{
			CMyStack<int> stack1;
			stack1.Push(1);
			stack1 = stack1;
			THEN("The stack should have the original elements")
			{
				REQUIRE(stack1.Top() == 1);
				REQUIRE(stack1.GetSize() == 1);
			}
		}
	}
}