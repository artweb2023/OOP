#include "WordFreq.h"

int main()
{
	WordFreq wordFreq;
	ReadFromInputStream(std::cin, wordFreq);
	PrintWordFreq(wordFreq);
	return 0;
}
