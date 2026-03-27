#include "str.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "=== Тесты для acronim ===" << std::endl;
    std::vector<std::string> words1 = {"tomorrow", "people", "university"};
    std::cout << "Тест 1: acronim(\"tpu\", [\"tomorrow\", \"people\", \"university\"]) = ";
    std::cout << acronim("tpu", words1) << std::endl;
    std::vector<std::string> words2 = {"tomorrow", "university", "people"};
    std::cout << "Тест 2: acronim(\"tpu\", [\"tomorrow\", \"university\", \"people\"]) = ";
    std::cout << acronim("tpu", words2) << std::endl;
    std::cout << "=== Тесты для pallindrom ===" << std::endl;
    std::cout << "Тест 1: pallindrom(\"never odd or even\") = ";
    std::cout << pallindrom("never odd or even") << std::endl;
    std::cout << "Тест 2: pallindrom(\"hello world\") = ";
    std::cout << pallindrom("hello world") << std::endl;
    std::cout << "=== Тесты для maxscore ===" << std::endl;
    //Настройка очков для букв
    std::vector<int> scores(26);
    for(int i = 0; i < 26; i++) scores[i] = i + 1; 
    std::vector<std::string> testWords2 = {"ab", "cd", "ef"};
    std::vector<char> testLetters2 = {'a', 'b', 'c', 'd'};
    std::cout << "Тест 1: maxscore([\"ab\", \"cd\", \"ef\"], ['a','b','c','d']) = ";
    std::cout << maxscore(testWords2, testLetters2, scores) << std::endl;
    std::vector<std::string> testWords3 = {"hello", "world"};
    std::vector<char> testLetters3 = {'h', 'e', 'l', 'l', 'o'};
    std::cout << "Тест 2: maxscore([\"hello\", \"world\"], ['h','e','l','l','o']) = ";
    std::cout << maxscore(testWords3, testLetters3, scores) << std::endl;
    return 0;
}
