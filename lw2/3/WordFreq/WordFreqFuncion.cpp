#include "WordFreq.h"

bool IsLetter(char ch)
{
	return isalpha(ch);
}

// использовать STL алгоритмы
std::string UpperToLower(const std::string& word) {
	std::string result;
	std::copy_if(word.begin(), word.end(), std::back_inserter(result), [](unsigned char ch) {
		return IsLetter(ch);
		});
	std::transform(result.begin(), result.end(), result.begin(), [](unsigned char ch) {
		return tolower(ch);
		});
	return result;
}
// не надо возвращать копию map
void WordCounting(WordFreq& wordFreq, const std::string& str)
{
	std::string word = UpperToLower(str);
	if (!word.empty())
	{
		wordFreq[word] += 1;
	}
	// использовать [] , если слово не пустое тогда увеличить частоту
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

// улучшить читаемость
void PrintWordFreq(const WordFreq& wordFreq)
{
	for (const auto& [word, freq] : wordFreq)
	{
		std::cout << word << ": " << freq << std::endl;
	}
}