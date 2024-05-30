#pragma once

#include <iostream>
#include <sstream>
#include <string>

constexpr unsigned int minAge = 14;
constexpr unsigned int maxAge = 60;

class CStudent
{
public:
	CStudent(std::string name, std::string surname, std::string patronymic, int age);
	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetPatronymic() const;
	int GetAge() const;
	void Rename(std::string name, std::string surname, std::string patronymic);
	void SetAge(int age);
private:
	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	int m_age;
};