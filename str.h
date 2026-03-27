#ifndef STR_H
#define STR_H

#include <iostream>
#include <string>
#include <vector>

bool acronim(std::string s, std::vector<std::string> words);
bool pallindrom(std::string s);
int maxscore(std::vector<std::string> words, std::vector<char> letters, std::vector<int> score);

#endif