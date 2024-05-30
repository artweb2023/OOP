#define CATCH_CONFIG_MAIN
#include "../StringStack/CStringStack.h"
#include "/OOP/catch2/catch.hpp"

// добавить присваение самому себе;

SCENARIO("Testing CStringStack")
{
	GIVEN("An empty CStringStack")
	{
		CStringStack stack;
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
			CStringStack copiedStack = stack;
			THEN("The copied stack should have the same elements as the original")
			{
				REQUIRE(copiedStack.GetSize() == stack.GetSize());
				REQUIRE(copiedStack.Top() == stack.Top());
			}
		}
		WHEN("The stack is moved")
		{
			stack.Push("original");
			CStringStack movedStack = std::move(stack);
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
			CStringStack stack1;
			stack1.Push("one");
			stack1.Push("two");
			CStringStack stack2;
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
			CStringStack stack1;
			stack1.Push("one");
			stack1.Push("two");
			CStringStack stack2;
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
			CStringStack stack1;
			stack1.Push("one");
			stack1 = stack1;
			THEN("The moved-to stack should have the original elements and the original should be empty")
			{
				REQUIRE(stack1.Top() == "one");
				REQUIRE(stack1.GetSize() == 1);
			}
		}
	}
}
