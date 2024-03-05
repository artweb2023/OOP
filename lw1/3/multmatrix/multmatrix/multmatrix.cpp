#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>

struct Args
{
	std::string fileOne;
	std::string fileTwo;
};

struct Matrices
{
	std::array<std::array<double, 3>, 3> matrixOne;
	std::array<std::array<double, 3>, 3> matrixTwo;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
		return std::nullopt;
	}
	Args args;
	args.fileOne = argv[1];
	args.fileTwo = argv[2];
	return args;
}

bool IsOpenFile(std::ifstream& input, const std::string& file)
{
	input.open(file);
	if (!input.is_open())
	{
		return false;
	}
	return true;
}

// использовать массивы array
// дать другое имя функция обозначает действие
bool WriteFromFile(std::ifstream& input, std::array<std::array<double, 3>, 3>& matrix)
{
	if (input.bad())
	{
		return false;
	}
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!(input >> matrix[i][j]))
			{
				return false;
			}
			count++;
		}
	}
	if (count < 9)
	{
		return false;
	}
	return input.eof();
}

// дать другое имя функции
// не передавать в опционал функции если функции надо тока значение
// написать функцию которая считывает одну матрицу
bool CheckFileData(const std::string& fileName, Matrices& matrices)
{
	std::ifstream inputFile;
	if (!IsOpenFile(inputFile, fileName))
	{
		std::cout << "Failed to open '" << fileName << "' file\n";
		return false;
	}
	if (!WriteFromFile(inputFile, matrices.matrixOne))
	{
		std::cout << "Failed to read in the '" << fileName << "' file\n";
		return false;
	}
	inputFile.close();
	return true;
}

// переименовать функции
void PrintMultiplyMatrix(const Matrices& matrices)
{
	double result[3][3] = { 0 };
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			for (int inner = 0; inner < 3; inner++) {
				result[row][col] += matrices.matrixOne[row][inner] * matrices.matrixTwo[inner][col];
			}
			std::cout << std::fixed << std::setprecision(3) << result[row][col] << " ";
		}
		std::cout << "\n";
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
	Matrices matrices;
	if (!CheckFileData(args->fileOne, matrices) && !CheckFileData(args->fileTwo, matrices))
	{
		return 1;
	}
	PrintMultiplyMatrix(matrices);
	return 0;
}

