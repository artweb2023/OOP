#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

// ����� ������� matrix1FileName
struct Args
{
	std::string matrix1FileName;
	std::string matrix2FileName;
};

//������������ Matrix3x3 
using Matrix3x3 = std::array<std::array<double, 3>, 3>;

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
		return std::nullopt;
	}
	Args args;
	args.matrix1FileName = argv[1];
	args.matrix2FileName = argv[2];
	return args;
}

//������ �������
// ������������ ������� array
// ���� ������ ��� ������� ���������� ��������
// ����� �������� ��� ���� input.bad()
bool ReadFileStream(std::ifstream& input, std::array<std::array<double, 3>, 3>& matrix)
{
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
	if (count < 3 * 3)
	{
		return false;
	}
	return input.eof();
}

// ���� ������ ��� �������
// �� ���������� � �������� ������� ���� ������� ���� ���� ��������
// �������� ������� ������� ��������� ���� ������� ReadMatrixFromFile

bool ReadMatrixFromFile(const std::string& fileName, Matrix3x3& matrix)
{
	std::ifstream inputFile;
	inputFile.open(fileName);
	if (!inputFile.is_open())
	{
		// ������� ���������� � ������� �� ����������
		throw std::runtime_error("Failed to open '" + fileName + "' file");
	}
	if (!ReadFileStream(inputFile, matrix))
	{
		throw std::runtime_error("Failed to read from '" + fileName + "' file");
	}
	return true;
}

// ������������� �������
// ����� ���������� ������ ������� �� �����������
// �������� ��������� , �������� ������� ��������
// result �� ���� ��������� ����������� ������
Matrix3x3 MultiplyMatrix(Matrix3x3& matrixOne, Matrix3x3& matrixTwo)
{
	Matrix3x3 result = { 0 };
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			for (int inner = 0; inner < 3; inner++) {
				result[row][col] += matrixOne[row][inner] * matrixTwo[inner][col];
			}
		}
	}
	return result;
}

void PrintMatrix(const Matrix3x3& matrices)
{
	auto defaultPrecision = std::cout.precision();
	std::cout << std::fixed << std::setprecision(3);
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			// ������� �� ������ � ������� ��� ���� ����� ������ (����� � ��������� ���������)
			std::cout << matrices[row][col] << " ";
		}
		std::cout << "\n";
	}
	std::cout << std::setprecision(defaultPrecision) << std::endl;
}

int main(int argc, char* argv[])
{
	try
	{
		auto args = ParseArgs(argc, argv);
		if (!args)
		{
			return 1;
		}
		Matrix3x3 matrixOne;
		Matrix3x3 matrixTwo;
		ReadMatrixFromFile(args->matrix1FileName, matrixOne);
		ReadMatrixFromFile(args->matrix2FileName, matrixTwo);
		PrintMatrix(MultiplyMatrix(matrixOne, matrixTwo));
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
}
