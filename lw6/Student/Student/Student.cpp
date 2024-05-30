#include "CStudent.h"

int main()
{
	try
	{
		std::string name, surname, patronymic;
		int age;
		std::cout << "Enter your name: ";
		std::cin >> name;
		std::cout << "Enter your surname: ";
		std::cin >> surname;
		std::cout << "Enter your patronymic: ";
		std::cin >> patronymic;
		std::cout << "Enter your age: ";
		std::cin >> age;
		CStudent student(name, surname, patronymic, age);
		std::cout << student.GetName() << " "
			<< student.GetSurname() << " "
			<< student.GetPatronymic() << " "
			<< student.GetAge() << std::endl;
		std::cout << "Rename: ";
		std::cin >> name >> surname >> patronymic;
		std::cout << "Change age: ";
		std::cin >> age;
		std::cout << std::endl;
		std::cout << student.GetName() << " "
			<< student.GetSurname() << " "
			<< student.GetPatronymic() << " "
			<< student.GetAge() << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Error full name: " << e.what() << std::endl;
	}
	catch (const std::domain_error& e)
	{
		std::cout << "Error age: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
