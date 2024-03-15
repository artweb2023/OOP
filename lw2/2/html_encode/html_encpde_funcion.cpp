#include "html_encode.h"

const std::map<char, std::string> mnemonics = {
	{ '"', "&quot;" },
	{ '\'', "&apos;" },
	{ '<', "&lt;" },
	{ '>', "&gt;"},
	{ '&', "&amp;" },
};

std::string HtmlEncode(const std::string& html)
{
	std::string result;
	for (size_t position = 0; position < html.length(); ++position)
	{
		bool encoded = false;
		for (const auto& [symbol, mnemonic] : mnemonics)
		{
			if (html[position] == symbol)
			{
				result.append(mnemonic);
				encoded = true;
				break;
			}
		}
		if (!encoded)
			result += html[position];
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