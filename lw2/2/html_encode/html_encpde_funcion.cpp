#include "html_encode.h"

//использовать array std::pair
const std::array<std::pair<char, std::string>, 5> mnemonics{
	{
		{ '"', "&quot;" },
		{'\'', "&apos;"},
		{'<', "&lt;"},
		{'>', "&gt;"},
		{'&', "&amp;"}
	}
};

// использовать range base
// если использовать map то использовать метод find
std::string HtmlEncode(const std::string& html)
{
	std::string result;
	for (auto ch : html)
	{
		bool encoded = false;
		for (auto& [symbol, mnemonic] : mnemonics)
		{
			if (ch == symbol)
			{
				result.append(mnemonic);
				encoded = true;
				break;
			}
		}
		if (!encoded)
		{
			result.push_back(ch);
		}
	}
	return result;
}

void EncodeInputStream(std::istream& inputStream, std::ostream& outputStream)
{
	std::string line;

	while (std::getline(inputStream, line))
	{
		outputStream << HtmlEncode(line) << std::endl;
	}
}