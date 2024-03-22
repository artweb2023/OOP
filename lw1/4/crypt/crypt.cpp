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
	return args;
}

//переименовать функцию 
bool CheckFile(std::ifstream& input, std::ofstream& output)
{
	if (!input.is_open())
	{
		throw std::runtime_error("Failed to open input file");
	}
	if (!output.is_open())
	{
		throw std::runtime_error("Failed to open output file");
	}
	return true;
}

// использовать двоичную систему
unsigned char EncryptSwapBits(unsigned char byte)
{
	return ((byte << 2) & 0b00011100) | ((byte >> 5) & 0b00000011)
		| ((byte << 3) & 0b11000000) | ((byte >> 2) & 0b00100000);
}

unsigned char DecryptSwapBits(unsigned char byte)
{
	return ((byte & 0b00011100) >> 2) | ((byte & 0b00000011) << 5)
		| ((byte & 0b11000000) >> 3) | ((byte & 0b00100000) << 2);
}
// нужно возращать байт а не строку
// сделать разные функции для перемешивания битов
unsigned SelectOperatingMode(char ch, const uint8_t key, Operation mode)
{
	unsigned char encryptionCh;
	unsigned char decryptionCh;
	switch (mode)
	{
	case Operation::Crypt:
	{
		return encryptionCh = EncryptSwapBits(ch ^ key);
	}
	case Operation::Decrypt:
	{
		return decryptionCh = DecryptSwapBits(ch) ^ key;
	}
	default:
		return ch;
	}
}

bool WriteInFileStream(unsigned char ch, std::ofstream& output)
{
	if (!output.put(ch))
	{
		return false;
	}
	return true;
}

// слишком много аргументов , не надо передавать больше аргументов чем нужно. 
bool ReadFromFileStream(std::ifstream& input, std::ofstream& output, Operation mode, const uint8_t key)
{
	// читать по байтово
	char ch;
	while (input.get(ch))
	{
		ch = SelectOperatingMode(ch, key, mode);
		if (!WriteInFileStream(ch, output))
		{
			return false;
		}
	}
	return input.eof();
}
// переименовать или расмотреть нужна ли функция
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

// не передавать optional
// файлы следует открывать прямо в этой функции
	// не совмещать вводы вывод
bool ProcessOperationMode(const std::string& inputFile, const std::string& outputFile,
	Operation mode, const uint8_t key)
{
	std::ifstream input;
	std::ofstream output;
	input.open(inputFile, std::ios_base::binary);
	output.open(outputFile, std::ios_base::binary);
	CheckFile(input, output);
	if (!ReadFromFileStream(input, output, mode, key))
	{
		throw std::runtime_error("Failed to copy crypt or decrypt data");
	}
	if (!CheckFileData(input, output))
	{
		throw std::runtime_error("Failed to read or write data");
	}
	return true;
}

//Добавить тест компресирование исполняемого файла
int main(int argc, char* argv[])
{
	try
	{
		auto args = ParseArgs(argc, argv);
		if (!args)
		{
			return 1;
		}
		if (!ProcessOperationMode(args->inputFile, args->outputFile, args->mode, args->key))
		{
			return 1;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}