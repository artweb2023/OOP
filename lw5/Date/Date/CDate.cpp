#include "CDate.h"

namespace
{
	// использовать g_ в названии констант
	constexpr unsigned int g_startYear = 1970;
	constexpr unsigned int g_maxTimeStamp = 2932896;
	constexpr unsigned int g_daysInNonLeapYear = 365;

	bool IsLeapYear(unsigned int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	unsigned int DaysInMonth(Month month, unsigned int year)
	{
		switch (month)
		{
		case Month::JANUARY:
		case Month::MARCH:
		case Month::MAY:
		case Month::JULY:
		case Month::AUGUST:
		case Month::OCTOBER:
		case Month::DECEMBER:
			return 31;
		case Month::APRIL:
		case Month::JUNE:
		case Month::SEPTEMBER:
		case Month::NOVEMBER:
			return 30;
		case Month::FEBRUARY:
			return IsLeapYear(year) ? 29 : 28;
		default:
			return 0;
		}
	}
	// подумать как упростить и обрезать дублирование кода
	DateStruct TimestampToDate(unsigned int days)
	{
		auto leapYearsInRange = [](unsigned int years) {
			return years / 4 - years / 100 + years / 400;
			};
		unsigned int year = g_startYear + ((days - (leapYearsInRange(days / g_daysInNonLeapYear))) / g_daysInNonLeapYear);
		const unsigned int countLeapYears = leapYearsInRange(year) - leapYearsInRange(g_startYear);
		days -= (year - g_startYear) * g_daysInNonLeapYear + countLeapYears - (IsLeapYear(year) ? 1 : 0);
		unsigned int month = 1;
		unsigned int daysInMonth = DaysInMonth(static_cast<Month>(month), year);
		while (month <= 12 && days >= DaysInMonth(static_cast<Month>(month), year))
		{
			days -= daysInMonth;
			if (days >= 0)
			{
				month++;
				daysInMonth = DaysInMonth(static_cast<Month>(month), year);
			}
		}
		return { days + 1, month, year };
	}
}

CDate::CDate(unsigned int day, Month month, unsigned int year)
	: m_timestamp(0)
{
	if (year >= g_startYear)
	{
		unsigned int totalDays = (year - g_startYear) * g_daysInNonLeapYear;
		totalDays += ((year - 1) / 4 - (g_startYear - 1) / 4)
			- ((year - 1) / 100 - (g_startYear - 1) / 100)
			+ ((year - 1) / 400 - (g_startYear - 1) / 400);
		// сравнивать enum значениями переделать
		if (month >= static_cast<Month>(1) && month <= static_cast<Month>(12))
		{
			for (unsigned int i = 1; i < static_cast<unsigned int>(month); ++i)
			{
				totalDays += DaysInMonth(static_cast<Month>(i), year);
			}

			if (day >= 1 && day <= DaysInMonth(month, year))
			{
				m_timestamp = totalDays + day - 1;
			}
		}
	}
}

// сделать проверку валидации даты
CDate::CDate(unsigned int timestamp)
	: m_timestamp(timestamp)
{
}

CDate::CDate()
	: m_timestamp(0)
{
}

unsigned int CDate::GetDay() const
{
	if (!IsValid())
	{
		return 0;
	}

	DateStruct date = TimestampToDate(m_timestamp);
	return date.day;
}

Month CDate::GetMonth() const
{
	if (!IsValid())
	{
		return Month::NONE;
	}

	DateStruct date = TimestampToDate(m_timestamp);
	return static_cast<Month>(date.month);
}

unsigned int CDate::GetYear() const
{
	if (!IsValid())
	{
		return 0;
	}

	DateStruct date = TimestampToDate(m_timestamp);
	return date.year;
}

WeekDay CDate::GetWeekDay() const
{
	// сделать константу из магического числа
	if (!IsValid())
	{
		return WeekDay::NONE;
	}
	return static_cast<WeekDay>((m_timestamp + 4) % 7);
}

bool CDate::IsValid() const
{
	return m_timestamp > 0 && m_timestamp < g_maxTimeStamp;
}

unsigned int CDate::GetTimestamp() const
{
	return m_timestamp;
}

CDate& CDate::operator++()
{
	if (IsValid())
	{
		++m_timestamp;
	}

	return *this;
}

CDate CDate::operator++(int)
{
	CDate temp = *this;
	if (IsValid())
	{
		++m_timestamp;
	}

	return temp;
}


CDate& CDate::operator--()
{
	if (IsValid())
	{
		m_timestamp--;
	}
	return *this;
}

CDate CDate::operator--(int)
{
	CDate date = *this;
	if (IsValid())
	{
		m_timestamp--;
	}
	return date;
}

CDate CDate::operator+(int days) const
{
	if (IsValid() && m_timestamp <= g_maxTimeStamp - days)
	{
		return CDate(m_timestamp + days);
	}

	return *this;
}

CDate CDate::operator-(int days) const
{
	if (IsValid() && m_timestamp >= static_cast<unsigned int>(days))
	{
		return CDate(m_timestamp - days);
	}
	return *this;
}

// добавить проверку на валидацию даты
int CDate::operator-(const CDate& date) const
{
	return this->GetTimestamp() - date.GetTimestamp();
}

CDate& CDate::operator+=(int days)
{
	if (IsValid())
	{
		m_timestamp += days;
	}

	return *this;
}


CDate& CDate::operator-=(int days)
{
	if (IsValid())
	{
		m_timestamp -= days;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const CDate& date)
{
	if (!date.IsValid())
	{
		return os << "INVALID";
	}

	DateStruct dateSt = ::TimestampToDate(date.m_timestamp);
	return os << std::format("{:02d}.{:02d}.{}", dateSt.day, dateSt.month, dateSt.year);
}

std::istream& operator>>(std::istream& is, CDate& date)
{
	DateStruct dateSt{};
	char delimiter = '.';

	if (is >> dateSt.day >> delimiter && delimiter == '.'
		&& is >> dateSt.month >> delimiter && delimiter == '.'
		&& is >> dateSt.year)
	{
		date = CDate(dateSt.day, static_cast<Month>(dateSt.month), dateSt.year);
	}
	else
	{
		is.setstate(std::ios::badbit);
	}

	return is;
}


CDate operator+(int days, const CDate& date)
{
	return CDate(days + date.GetTimestamp());
}
