#include <fstream>
#include <iostream>
#include <limits>
#include <optional>
#include <string>

enum class Operation
{
	Crypt,
	Decrypt,
	None,
};

struct Args
{
	Operation mode = Operation::None;
	std::string inputFile;
	std::string outputFile;
	uint8_t key = 0;
};

bool IsValidKey(int key)
{
	if (key < 0 || key > std::numeric_limits<uint8_t>::max())
	{
		return false;
	}
	return true;
}

bool IsOperationMode(const std::string& crypt, Args& args)
{
	if (crypt == "crypt")
	{
		args.mode = Operation::Crypt;
		return true;
	}
	else if (crypt == "decrypt")
	{
		args.mode = Operation::Decrypt;
		return true;
	}
	return false;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: crypt.exe crypt <input file> <output file> <key> \n";
		return std::nullopt;
	}
	Args args;
	try
	{
		int key = std::stoi(argv[4]);
		if (!IsValidKey(key))
		{
			std::cout << "Invalid arguments key\n";
			std::cout << "Usage: <key> 0-255\n";
			return std::nullopt;
		}
		if (!IsOperationMode(argv[1], args))
		{
			std::cout << "Usage: crypt or decrypt\n";
			return std::nullopt;
		}
		args.inputFile = argv[2];
		args.outputFile = argv[3];
		args.key = static_cast<uint8_t>(key);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return std::nullopt;
	}
	return args;
}

bool IsOpenFile(std::ifstream& input, std::ofstream& output, std::optional<Args>& args)
{
	input.open(args->inputFile);
	if (!input.is_open())
	{
		return false;
	}
	output.open(args->outputFile);
	if (!output.is_open())
	{
		return false;
	}
	return true;
}

unsigned char SwapBits(unsigned char byte, Operation mode)
{
	switch (mode)
	{
	case Operation::Crypt:
		return ((byte << 2) & 0x1C) | ((byte >> 5) & 0x03) | ((byte << 3) & 0xC0) | ((byte >> 2) & 0x20);
	case Operation::Decrypt:
		return ((byte & 0x1C) >> 2) | ((byte & 0x03) << 5) | ((byte & 0xC0) >> 3) | ((byte & 0x20) << 2);
	default:
		return byte;
	}
}

std::string SelectOperatingMode(const std::string& str, std::optional<Args> args)
{
	std::string encryptionStr;
	for (unsigned char ch : str)
	{
		switch (args->mode)
		{
		case Operation::Crypt:
		{
			encryptionStr += SwapBits(ch ^ args->key, args->mode);
			break;
		}
		case Operation::Decrypt:
		{
			encryptionStr += SwapBits(ch, args->mode) ^ args->key;
			break;
		}
		default:
			break;
		}
	}
	return encryptionStr;
}

bool ReadAndWriteFromFileStream(std::ifstream& input, std::ofstream& output, std::optional<Args> args)
{
	std::string str;
	while (getline(input, str))
	{
		str = SelectOperatingMode(str, args) + '\n';
		if (!(output << str))
		{
			return false;
		}
	}
	return input.eof();
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

bool ProcessingOperatingMode(std::optional<Args> args)
{
	std::ifstream input;
	std::ofstream output;
	if (!IsOpenFile(input, output, args))
	{
		std::cout << "Failed to open file\n";
		return false;
	}
	if (!ReadAndWriteFromFileStream(input, output, args))
	{
		std::cout << "Failed to copy crypt or decrypt data\n";
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
	if (!ProcessingOperatingMode(args))
	{
		return 1;
	}
	return 0;
}