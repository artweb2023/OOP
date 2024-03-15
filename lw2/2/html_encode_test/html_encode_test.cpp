#define CATCH_CONFIG_MAIN

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw2/2/html_encode/html_encode.h"
#include <iostream>


SCENARIO("HTML code encoding")
{
	GIVEN("Testing a function for a correct value")
	{
		std::istringstream input("Cat <says> \"Meow\". M&M\'s\n");
		std::ostringstream output("");
		std::string encode = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s\n";

		WHEN("EncodeInputStream is called")
		{
			EncodeInputStream(input, output);

			THEN("The string is encoded")
			{
				REQUIRE(output.str() == encode);
			}
		}
	}
	GIVEN("Testing a function for empty value")
	{
		std::istringstream input("");
		std::ostringstream output("");

		WHEN("EncodeInputStream is called")
		{
			EncodeInputStream(input, output);

			THEN("The output should be empty")
			{
				REQUIRE(input.str() == output.str());
			}
		}
	}
	GIVEN("Testing a function for a string without special characters")
	{
		std::istringstream input("This is a test without special characters");
		std::ostringstream output("");
		std::string encode = "This is a test without special characters\n";

		WHEN("EncodeInputStream is called")
		{
			EncodeInputStream(input, output);

			THEN("The output should be the same as the input")
			{
				REQUIRE(output.str() == encode);
			}
		}
	}
	GIVEN("Testing a function for a string with all special characters")
	{
		std::istringstream input("\"\'&<>\"");
		std::ostringstream output("");
		std::string encode = "&quot;&apos;&amp;&lt;&gt;&quot;\n";

		WHEN("EncodeInputStream is called")
		{
			EncodeInputStream(input, output);

			THEN("The output should contain encoded special characters")
			{
				REQUIRE(output.str() == encode);
			}
		}
	}
}