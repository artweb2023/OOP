#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

typedef std::map<std::string, int> WordFreq;

void ReadFromInputStream(std::istream& inputStream, WordFreq& word);
void PrintWordFreq(const WordFreq& wordFreq);