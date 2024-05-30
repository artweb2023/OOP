#define CATCH_CONFIG_MAIN

#include "/OOP/catch2/catch.hpp"
#include "/OOP/lw6/Student/Student/CStudent.h"

SCENARIO("Testing CStudent")
{
	GIVEN("CStudent")
	{
		WHEN("Creating class CStudent")
		{
			CStudent student("Ivan", "Ivanov", "Ivanovich", 16);
			THEN("Check student information")
			{
				REQUIRE(student.GetName() == "Ivan");
				REQUIRE(student.GetSurname() == "Ivanov");
				REQUIRE(student.GetPatronymic() == "Ivanovich");
				REQUIRE(student.GetAge() == 16);
			}
		}
		WHEN("Renaming student")
		{
			CStudent student("Ivan", "Ivanov", "Ivanovich", 16);
			student.Rename("Petr", "Petrov", "");
			THEN("Check updated information")
			{
				REQUIRE(student.GetName() == "Petr");
				REQUIRE(student.GetSurname() == "Petrov");
				REQUIRE(student.GetPatronymic() == "");
			}
		}
		WHEN("Creating class CStudent with invalid age")
		{
			THEN("An exception should be thrown")
			{
				REQUIRE_THROWS_AS(CStudent("John", "Doe", "Doe", 12), std::out_of_range);
			}
		}
		WHEN("Creating class CStudent with empty patronymic")
		{
			CStudent student("John", "Doe", "", 18);
			THEN("The patronymic should be empty")
			{
				REQUIRE(student.GetPatronymic() == "");
			}
		}
		WHEN("Setting age")
		{
			CStudent student("Ivan", "Ivanov", "Ivanovich", 16);
			student.SetAge(18);
			THEN("Check updated age")
			{
				REQUIRE(student.GetAge() == 18);
			}
		}
		WHEN("Setting age with invalid value")
		{
			CStudent student("Ivan", "Ivanov", "Ivanovich", 16);
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(student.SetAge(15), std::domain_error);
			}
		}
		WHEN("Setting age with invalid range value")
		{
			CStudent student("Ivan", "Ivanov", "Ivanovich", 16);
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(student.SetAge(62), std::out_of_range);
			}
		}
		WHEN("Renaming with invalid name")
		{
			CStudent student("Ivan", "Ivanov", "Ivanovich", 16);
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(student.Rename(" ", "Petrov", "Petrovich"), std::invalid_argument);
			}
		}
		WHEN("class CStudent have invalid surname")
		{
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(CStudent("Ivan", "Iva Iva  Iva", "Ivanovich", 16), std::invalid_argument);
			}
		}
		WHEN("class CStudent have empty surname")
		{
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(CStudent("Ivan", "", "Ivanovich", 16), std::invalid_argument);
			}
		}
		WHEN("Renaming with empty name")
		{
			CStudent student("Ivanov", "Ivanov", "Ivanovich", 16);
			THEN("Check if exception is thrown")
			{
				REQUIRE_THROWS_AS(student.Rename("", "Petrov", "Petrovich"), std::invalid_argument);
			}
		}
	}
}
