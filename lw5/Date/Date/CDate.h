#pragma once
#include <format>
#include <iostream>

enum class Month
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
	NONE
};

enum class WeekDay
{
	SUNDAY = 0,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	NONE
};

// переменновать взять более осмысленное название
struct DateStruct
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

class CDate
{
public:
	CDate(unsigned int day, Month month, unsigned int year);
	explicit CDate(unsigned int timestamp);
	CDate();
	unsigned int GetDay()const;
	Month GetMonth()const;
	unsigned int GetYear()const;
	WeekDay GetWeekDay()const;
	bool IsValid() const;
	unsigned int GetTimestamp() const;
	CDate& operator++();
	CDate operator++(int);
	CDate& operator--();
	CDate operator--(int);
	CDate operator+(int days) const;
	CDate operator-(int days) const;
	int operator-(const CDate& date) const;
	CDate& operator+=(int days);
	CDate& operator-=(int days);
	auto operator<=>(CDate const& date) const = default;
	friend std::ostream& operator<<(std::ostream& stream, const CDate& date);
	friend std::istream& operator>>(std::istream& stream, CDate& date);
	friend CDate operator+(int days, const CDate& date);
private:
	unsigned int m_timestamp;
};

