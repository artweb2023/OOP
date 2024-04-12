#include "CCanvas .h"
#include "CRectangle.h"
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

struct Args
{
	std::string fileNameRectangle1;
	std::string fileNameRectangle2;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: rectangle.exe <rectangle file1> <rectangle file2>\n";
		return std::nullopt;
	}
	Args args;
	args.fileNameRectangle1 = argv[1];
	args.fileNameRectangle2 = argv[2];
	return args;
}

void RunCommand(const std::string& cmd, std::istringstream& iss, CRectangle& rectangle)
{
	if (cmd == "Rectangle")
	{
		int left, top, width, height;
		iss >> left >> top >> width >> height;
		rectangle = CRectangle({ left, top }, width, height);
	}
	else if (cmd == "Move")
	{
		int dx, dy;
		iss >> dx >> dy;
		rectangle.Move(dx, dy);
	}
	else if (cmd == "Scale")
	{
		int sx, sy;
		iss >> sx >> sy;
		rectangle.Scale(sx, sy);
	}
}

bool ProcessCommand(const std::string& command, CRectangle& rectangle)
{
	std::istringstream iss(command);
	std::string cmd;
	if (!(iss >> cmd))
	{
		return false;
	}
	RunCommand(cmd, iss, rectangle);
	return true;
}

bool ReadComand(std::ifstream& file, CRectangle& rectangle)
{
	std::string line;
	while (std::getline(file, line))
	{
		if (!ProcessCommand(line, rectangle))
		{
			return false;
		}
	}
	return true;
}

bool ReadRectangleFromFile(CRectangle& rectangle, std::string fileName)
{
	std::ifstream input;
	input.open(fileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" + fileName + "' file" << std::endl;
		return false;
	}
	if (!ReadComand(input, rectangle))
	{
		return false;
	}
	return true;
}

void Print(const CRectangle& rectangle)
{
	std::cout << "Rectangle :\n";
	std::cout << "    Left top: (" << rectangle.GetLeftTop().x << "; " << rectangle.GetLeftTop().y << ")\n";
	std::cout << "    Size: " << rectangle.GetWidth() << "*" << rectangle.GetHeight() << "\n";
	std::cout << "    Right bottom: (" << rectangle.GetRightBottom().x << "; " << rectangle.GetRightBottom().y << ")\n";
	std::cout << "    Area: " << rectangle.GetArea() << "\n";
	std::cout << "    Perimeter: " << rectangle.GetPerimeter() << "\n";
}

void PrintIntersect(CRectangle& rectangle1, const CRectangle& rectangle2) {
	CRectangle intersection({ 0, 0 }, 0, 0);
	if (rectangle1.Intersect(rectangle2))
	{
		intersection = rectangle1;
		std::cout << "Intersection rectangle:\n";
		std::cout << "    Left top: (" << intersection.GetLeftTop().x << "; " << intersection.GetLeftTop().y << ")\n";
		std::cout << "    Size: " << intersection.GetWidth() << "*" << intersection.GetHeight() << "\n";
		std::cout << "    Right bottom: (" << intersection.GetRightBottom().x << "; " << intersection.GetRightBottom().y << ")\n";
		std::cout << "    Area: " << intersection.GetArea() << "\n";
		std::cout << "    Perimeter: " << intersection.GetPerimeter() << "\n";
	}
	else
	{
		std::cout << "No intersection.\n";
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
	CRectangle rectangle1({ 0, 0 }, 0, 0);
	CRectangle rectangle2({ 0, 0 }, 0, 0);
	if (!ReadRectangleFromFile(rectangle1, args->fileNameRectangle1)
		|| !ReadRectangleFromFile(rectangle2, args->fileNameRectangle2))
	{
		return 1;
	}
	Print(rectangle1);
	Print(rectangle2);
	PrintIntersect(rectangle1, rectangle2);
	return 0;
}
