#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <optional>

constexpr int maxBit = 8;

enum class ErrorArgv
{
    ErrorByte,
    ErrorBits,
    None,
};

struct Args
{
    uint8_t byte;
    int size;
    bool isLeft;
};

//функци€ ничего не должна знать откуда была вызвана нельз€ смешивать код ошибки и результат функции
void RotateByte(std::optional<Args>& args) 
{
    unsigned char result;
    if (args->isLeft) 
    {
        result = (args->byte << args->size) | (args->byte >> (maxBit - args->size));
    }
    else
    {
        result = (args->byte >> args->size) | (args->byte << (maxBit - args->size));
    }
    std::cout << static_cast<int> (result) << std::endl;
}

 void ErrorDisplay(ErrorArgv errorType)
{
    switch (errorType)
    {
    case ErrorArgv::ErrorByte:
    {
        std::cout << "Argument byte out of range" << std::endl;
        return;
    }
    case ErrorArgv::ErrorBits:
    {
        std::cout << "Argument number of bits out of range" << std::endl;
        return;
    }
    default:
        return;
    }
}

bool IsValidArguments(int byte, int size, ErrorArgv& errorType)
{
    if (byte < 0 || byte > std::numeric_limits<uint8_t>::max())
    {
        errorType = ErrorArgv::ErrorByte;
        return false;
    }
    if (size < 0)
    {
        errorType = ErrorArgv::ErrorBits;
        return false;
    }
    return true;
}

//парсинг комнадной строки и аргументов
// сделать так что бы можно было отличить возрат значени€ 
 // использовать строки

bool IsLeft(std::string direction)
{
    if (direction == "L")
    {
        return true;
    }
    return false;
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: rotatebyte.exe <byte> <number of bits> <L / R>\n";
        return std::nullopt;
    }
    Args args;
    try
    {
        // провер€ть значени€€ до byte и size
        int byte = std::stoi(argv[1]);
        int size = std::stoi(argv[2]);
        ErrorArgv errorType = ErrorArgv::None;
        if (!IsValidArguments(byte, size, errorType))
        {
            ErrorDisplay(errorType);
            return std::nullopt;
        }
        args.byte = static_cast<uint8_t>(byte);
        args.size = size;
        args.isLeft = IsLeft(argv[3]);

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return std::nullopt;
    }
    return args;
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }
    RotateByte(args);
    return 0;
}