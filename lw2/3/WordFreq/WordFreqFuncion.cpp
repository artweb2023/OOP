#include "WordFreq.h"

bool IsLetter(char ch)
{
	return isalpha(ch);
}

std::string UpperToLower(std::string& word)
{
	std::string result;
	for (auto ch : word)
	{
		if (!IsLetter(ch))
		{
			break;
		}
		else if (isupper(ch))
		{
			result += tolower(ch);
		}
		else
		{
			result += ch;
		}
	}
	return result;
}

WordFreq WordCounting(WordFreq& wordFreq, std::string& word)
{
	word = UpperToLower(word);
	auto it = wordFreq.find(word);
	if (it != wordFreq.end() and !wordFreq.empty())
	{
		it->second++;
	}
	else if (!word.empty())
	{
		wordFreq.insert(std::make_pair(word, 1));
	}
	return wordFreq;
}

void ReadFromInputStream(std::istream& inputStream, WordFreq& wordFreq)
{
	std::string line;
	std::string word;
	while (std::getline(inputStream, line))
	{
		std::istringstream str(line);
		while (str >> word)
		{
			WordCounting(wordFreq, word);
		}
	}
}

void PrintWordFreq(const WordFreq& wordFreq)
{
	for (auto& wordInfo : wordFreq)
	{
		std::cout << wordInfo.first << ": " << wordInfo.second << std::endl;
	}
}