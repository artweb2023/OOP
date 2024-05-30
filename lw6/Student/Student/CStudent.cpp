#include "CStudent.h"


namespace
{
	const std::string& AssureNotSpaces(const std::string& str, const std::string& argName = std::string())
	{
		if (str.find_first_of(' ') == std::string::npos)
		{
			return str;
		}
		throw std::invalid_argument(argName.empty() ? "Argument" : argName + " cannot contain spaces");
	}
	const int AssureNotOutOfRange(const int age, const std::string& argName = std::string())
	{
		if (age >= minAge && age <= maxAge)
		{
			return age;
		}
		throw std::out_of_range(argName.empty() ? "Argument" : argName + " cannot out of range");
	}
}

CStudent::CStudent(std::string name, std::string surname, std::string patronymic, int age)
	: m_name(!name.empty() ? AssureNotSpaces(name, "name") : throw std::invalid_argument("name cannot be empty"))
	, m_surname(!surname.empty() ? AssureNotSpaces(surname, "surname") : throw std::invalid_argument("surname cannot be empty"))
	, m_patronymic(AssureNotSpaces(patronymic.empty() ? "" : patronymic, "patronymic"))
	, m_age(AssureNotOutOfRange(age, "Age"))
{
}

std::string CStudent::GetName() const
{
	return m_name;
}

std::string CStudent::GetSurname() const
{
	return m_surname;
}

std::string CStudent::GetPatronymic() const
{
	return m_patronymic;
}

int CStudent::GetAge() const
{
	return m_age;
}

void CStudent::Rename(std::string name, std::string surname, std::string patronymic)
{
	std::string prevName = m_name;
	std::string prevSurname = m_surname;
	std::string prevPatronymic = m_patronymic;
	try
	{
		m_name = !name.empty() ? AssureNotSpaces(name, "name") : throw std::invalid_argument("name cannot be empty");
		m_surname = !surname.empty() ? AssureNotSpaces(surname, "surname") : throw std::invalid_argument("surname cannot be empty");
		m_patronymic = AssureNotSpaces(patronymic.empty() ? "" : AssureNotSpaces(patronymic, "patronymic"));
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		m_name = prevName;
		m_surname = prevSurname;
		m_patronymic = prevPatronymic;
	}
}

void CStudent::SetAge(int age)
{
	if (m_age > age)
	{
		throw std::domain_error("Age cannot be reduced");
	}
	m_age = AssureNotOutOfRange(age, "Age");
}