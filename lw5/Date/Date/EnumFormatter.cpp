#include "EnumFormatter.h"


std::ostream& operator<<(std::ostream& os, const WeekDay weekday)
{
	switch (weekday)
	{
	case WeekDay::SUNDAY:
		return os << "Sunday";
	case WeekDay::MONDAY:
		return os << "Monday";
	case WeekDay::TUESDAY:
		return os << "Tuesday";
	case WeekDay::WEDNESDAY:
		return os << "Wednesday";
	case WeekDay::THURSDAY:
		return os << "Thursday";
	case WeekDay::FRIDAY:
		return os << "Friday";
	case WeekDay::SATURDAY:
		return os << "Saturday";
	default:
		return os << "No day of the week";
	}
}

std::ostream& operator<<(std::ostream& os, const Month month)
{
	switch (month)
	{
	case Month::JANUARY:
		return os << "January";
	case Month::FEBRUARY:
		return os << "February";
	case Month::MARCH:
		return os << "March";
	case Month::APRIL:
		return os << "April";
	case Month::MAY:
		return os << "May";
	case Month::JUNE:
		return os << "June";
	case Month::JULY:
		return os << "July";
	case Month::AUGUST:
		return os << "August";
	case Month::SEPTEMBER:
		return os << "September";
	case Month::OCTOBER:
		return os << "October";
	case Month::NOVEMBER:
		return os << "November";
	case Month::DECEMBER:
		return os << "December";
	default:
		return os << "No month";
	}
}