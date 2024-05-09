#include "CDate.h"
#include "EnumFormatter.h"


int main()
{

	CDate date(03, Month::MAY, 2024);
	std::cout << date << "\n";
	std::cout << date.GetWeekDay() << std::endl;
	std::cout << date.GetMonth() << std::endl;
	std::cout << date.GetYear() << std::endl;
	return 0;
}
