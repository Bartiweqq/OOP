#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <sstream>
#include <string>

bool isVowel(char c);
bool startsAndEndsWithVowel(const std::string& word);
void processWords(std::istringstream& iss);
void processFile(const std::string& filename);

#endif // FUNCTIONS_H
