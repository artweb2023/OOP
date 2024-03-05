#include <iostream>
#include <fstream>
#include <optional>
#include <string>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: copyfile.exe <input file name> <output file name>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

bool CopyStreams(std::ifstream& input, std::ofstream& output)
{
	char ch;
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			return false;
		}
	}
	return input.eof();
}

///Перименовать функцию, внутри себя открывать и копирует

bool CheckCopyFile(std::ifstream& input, std::ofstream& output, std::optional<Args>& args)
{
	input.open(args->inputFileName);
	if (!input.is_open())
	{
		return false;
	}
	output.open(args->outputFileName);
	if (!output.is_open())
	{
		return false;
	}
	return true;
}

bool CheckFileData(std::ifstream& input, std::ofstream& output)
{
	if (input.bad())
	{
		return false;
	}
	if (!output.flush())
	{
		return false;
	}
	return true;
}

bool CopyFile(std::optional<Args>& args)
{
	std::ifstream input;
	std::ofstream output;
	if (!CheckCopyFile(input, output, args))
	{
		std::cout << "Failed to open file\n";
		return false;
	}
	if (!CopyStreams(input, output))
	{
		std::cout << "Failed to copy data\n";
		return false;
	}
	if (!CheckFileData(input, output))
	{
		std::cout << "Failed to read or write data\n";
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
	if (!CopyFile(args))
	{
		return 1;
	}
	return 0;
}



