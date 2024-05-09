#define CATCH_CONFIG_MAIN
#include "../../../../../catch2/catch.hpp"
#include "../Date/CDate.h"

SCENARIO("Testing data initialization")
{
	GIVEN("Output stream")
	{
		std::ostringstream oss;
		WHEN("Creating class object with timestamp")
		{
			CDate date(1);
			oss << date;
			THEN("Date will be 02.01.1970")
			{
				REQUIRE(oss.str() == "02.01.1970");
			}
		}
	}
	GIVEN("Input stream")
	{
		std::istringstream iss("02.01.1970");
		WHEN("Initializing object from input stream")
		{
			CDate date;
			iss >> date;
			THEN("Date is initialized correctly")
			{
				REQUIRE(date.IsValid());
				REQUIRE(date.GetDay() == 2);
				REQUIRE(date.GetMonth() == Month::JANUARY);
				REQUIRE(date.GetYear() == 1970);
			}
		}
	}

	GIVEN("Valid date parameters")
	{
		unsigned int day = 15;
		Month month = Month::MARCH;
		unsigned int year = 2023;
		WHEN("Creating class object")
		{
			CDate date(day, month, year);
			THEN("Date is initialized correctly")
			{
				REQUIRE(date.IsValid());
				REQUIRE(date.GetDay() == day);
				REQUIRE(date.GetMonth() == month);
				REQUIRE(date.GetYear() == year);
			}
		}
	}

	GIVEN("Invalid date parameters")
	{
		unsigned int day = 31;
		Month month = Month::APRIL;
		unsigned int year = 2023;
		WHEN("Creating class object")
		{
			CDate date(day, month, year);
			THEN("Date is invalid")
			{
				REQUIRE_FALSE(date.IsValid());
			}
		}
	}
}


SCENARIO("Testing GetDay function")
{
	GIVEN("A valid date object")
	{
		CDate date(3, Month::MAY, 2024);
		WHEN("Calling GetDay")
		{
			unsigned int day = date.GetDay();
			THEN("It should return the correct day")
			{
				REQUIRE(day == 3);
			}
		}
	}
	GIVEN("An invalid date object")
	{
		CDate date(31, Month::APRIL, 2023);
		WHEN("Calling GetDay")
		{
			unsigned int day = date.GetDay();
			THEN("It should return 0")
			{
				REQUIRE(day == 0);
			}
		}
	}
}

SCENARIO("Testing GetMonth function")
{
	GIVEN("A valid date object")
	{
		CDate date(3, Month::MAY, 2024);
		WHEN("Calling GetMonth")
		{
			Month month = date.GetMonth();
			THEN("It should return the correct month")
			{
				REQUIRE(month == Month::MAY);
			}
		}
	}
	GIVEN("An invalid date object")
	{
		CDate date(31, Month::APRIL, 2023);
		WHEN("Calling GetMonth")
		{
			Month month = date.GetMonth();
			THEN("It should return a default month (likely 1)")
			{
				REQUIRE(month == Month::NONE);
			}
		}
	}
}

SCENARIO("Testing GetYear function")
{
	GIVEN("A valid date object")
	{
		CDate date(3, Month::MAY, 2024);
		WHEN("Calling GetYear")
		{
			unsigned int year = date.GetYear();
			THEN("It should return the correct year")
			{
				REQUIRE(year == 2024);
			}
		}
	}
	GIVEN("An invalid date object")
	{
		CDate date(31, Month::APRIL, 2023);
		WHEN("Calling GetYear")
		{
			unsigned int year = date.GetYear();
			THEN("It should return 0")
			{
				REQUIRE(year == 0);
			}
		}
	}
}

SCENARIO("Testing GetWeekDay function")
{
	GIVEN("A valid date object")
	{
		CDate date(3, Month::MAY, 2024);
		WHEN("Calling GetWeekDay")
		{
			WeekDay weekday = date.GetWeekDay();
			THEN("It should return the correct weekday")
			{
				REQUIRE(weekday == WeekDay::FRIDAY);
			}
		}
	}
	GIVEN("An invalid date object")
	{
		CDate date(31, Month::APRIL, 2023);
		WHEN("Calling GetWeekDay")
		{
			WeekDay weekday = date.GetWeekDay();
			THEN("It should return WeekDay::NONE")
			{
				REQUIRE(weekday == WeekDay::NONE);
			}
		}
	}
}

SCENARIO("Testing IsValid function")
{
	GIVEN("A valid date object")
	{
		CDate validDate(3, Month::MAY, 2024);
		WHEN("Calling IsValid")
		{
			bool isValid = validDate.IsValid();
			THEN("It should return true")
			{
				REQUIRE(isValid == true);
			}
		}
	}
	//по править ограничение
	GIVEN("An invalid date object")
	{
		CDate invalidDate(1, Month::JANUARY, 1969);
		WHEN("Calling IsValid")
		{
			bool isValid = invalidDate.IsValid();
			THEN("It should return false")
			{
				REQUIRE(isValid == false);
			}
		}
	}
}

SCENARIO("Testing increment operators")
{
	GIVEN("A date object at the end of a month")
	{
		CDate date(29, Month::FEBRUARY, 2024);
		WHEN("Calling postfix increment operator")
		{
			date++;
			THEN("Date should be incremented to 1st MARCH of the same year")
			{
				REQUIRE(date.GetDay() == 1);
				REQUIRE(date.GetMonth() == Month::MARCH);
				REQUIRE(date.GetYear() == 2024);
			}
		}
		WHEN("Calling prefix increment operator")
		{
			++date;
			THEN("Date should be incremented to 1st MARCH of the same year")
			{
				REQUIRE(date.GetDay() == 1);
				REQUIRE(date.GetMonth() == Month::MARCH);
				REQUIRE(date.GetYear() == 2024);
			}
		}
	}
	GIVEN("A date object at the end of a year")
	{
		CDate date(31, Month::DECEMBER, 2023);
		WHEN("Calling postfix increment operator")
		{
			date++;
			THEN("Date should be incremented to the next year")
			{
				REQUIRE(date.GetDay() == 1);
				REQUIRE(date.GetMonth() == Month::JANUARY);
				REQUIRE(date.GetYear() == 2024);
			}
		}
		WHEN("Calling prefix increment operator")
		{
			++date;
			THEN("Date should be incremented to the next year")
			{
				REQUIRE(date.GetDay() == 1);
				REQUIRE(date.GetMonth() == Month::JANUARY);
				REQUIRE(date.GetYear() == 2024);
			}
		}
	}
}

SCENARIO("Testing decrement operators")
{
	GIVEN("A date object at the start of a month")
	{
		CDate date(1, Month::MARCH, 2024);
		WHEN("Calling postfix increment operator")
		{
			date--;
			THEN("Date should be incremented to 1st MARCH of the same year")
			{
				REQUIRE(date.GetDay() == 29);
				REQUIRE(date.GetMonth() == Month::FEBRUARY);
				REQUIRE(date.GetYear() == 2024);
			}
		}
		WHEN("Calling prefix increment operator")
		{
			--date;
			THEN("Date should be incremented to 1st MARCH of the same year")
			{
				REQUIRE(date.GetDay() == 29);
				REQUIRE(date.GetMonth() == Month::FEBRUARY);
				REQUIRE(date.GetYear() == 2024);
			}
		}
	}
	GIVEN("A date object at the start of a year")
	{
		CDate date(1, Month::JANUARY, 2024);
		WHEN("Calling postfix increment operator")
		{
			date--;
			THEN("Date should be incremented to the next year")
			{
				REQUIRE(date.GetDay() == 31);
				REQUIRE(date.GetMonth() == Month::DECEMBER);
				REQUIRE(date.GetYear() == 2023);
			}
		}
		WHEN("Calling prefix increment operator")
		{
			--date;
			THEN("Date should be incremented to the next year")
			{
				REQUIRE(date.GetDay() == 31);
				REQUIRE(date.GetMonth() == Month::DECEMBER);
				REQUIRE(date.GetYear() == 2023);
			}
		}
	}
}

// добавить тест сначала число а потом дату 
SCENARIO("Testing arithmetic operators")
{
	GIVEN("A date object") {
		CDate date(31, Month::DECEMBER, 2023);
		WHEN("Adding days to the date using operator+")
		{
			CDate newDate = date + 5;
			THEN("The date should be incremented by the specified number of days")
			{
				REQUIRE(newDate.GetDay() == 5);
				REQUIRE(newDate.GetMonth() == Month::JANUARY);
				REQUIRE(newDate.GetYear() == 2024);
			}
		}
		WHEN("Subtracting days from the date using operator-")
		{
			CDate newDate = date - 10;
			THEN("The date should be decremented by the specified number of days")
			{
				REQUIRE(newDate.GetDay() == 21);
				REQUIRE(newDate.GetMonth() == Month::DECEMBER);
				REQUIRE(newDate.GetYear() == 2023);
			}
		}
		WHEN("Calculating the difference between two dates using operator-")
		{
			CDate otherDate(1, Month::JANUARY, 2023);
			int difference = date - otherDate;
			THEN("The difference should be the number of days between the two dates")
			{
				REQUIRE(difference == 364);
			}
		}
		WHEN("Adding days to the date using operator+=")
		{
			date += 7;
			THEN("The date should be incremented by the specified number of days")
			{
				REQUIRE(date.GetDay() == 7);
				REQUIRE(date.GetMonth() == Month::JANUARY);
				REQUIRE(date.GetYear() == 2024);
			}
		}

		WHEN("Subtracting days from the date using operator-=")
		{
			date -= 15;
			THEN("The date should be decremented by the specified number of days")
			{
				REQUIRE(date.GetDay() == 16);
				REQUIRE(date.GetMonth() == Month::DECEMBER);
				REQUIRE(date.GetYear() == 2023);
			}
		}
	}
}

SCENARIO("Testing Input/Output operators")
{
	GIVEN("Two date objects")
	{
		CDate date1(15, Month::JANUARY, 2023);
		CDate date2(20, Month::JANUARY, 2023);
		WHEN("Printing date to output stream using operator<<")
		{
			std::stringstream ss;
			ss << date1;
			THEN("The output should be in the format 'dd.mm.yyyy'")
			{
				REQUIRE(ss.str() == "15.01.2023");
			}
		}
		WHEN("Reading date from input stream using operator>>")
		{
			std::stringstream ss("01.02.2024");
			CDate date;
			ss >> date;
			THEN("The date should be correctly initialized")
			{
				REQUIRE(date.GetDay() == 1);
				REQUIRE(date.GetMonth() == Month::FEBRUARY);
				REQUIRE(date.GetYear() == 2024);
			}
		}
		WHEN("Adding days to the date using operator+")
		{
			CDate newDate = 5 + date1;
			THEN("The date should be incremented by the specified number of days")
			{
				REQUIRE(newDate.GetDay() == 20);
				REQUIRE(newDate.GetMonth() == Month::JANUARY);
				REQUIRE(newDate.GetYear() == 2023);
			}
		}
	}
}