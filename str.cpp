#include "str.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

bool acronim(std::string s, std::vector<std::string> words){
    if(s.size() != words.size()) return false;
    for(size_t i = 0; i < s.size(); i++) if(words[i].empty() || words[i][0] != s[i]) return false;
    return true;
}

bool pallindrom(std::string s){
    std::string clean;
    for(size_t i = 0; i < s.size(); i++) if(!std::isspace(s[i])) clean += s[i];
    for(size_t i = 0; i < clean.size() / 2; i++) if(clean[i] != clean[clean.size() - 1 - i]) return false;
    return true;
}

int maxscore(std::vector<std::string> words, std::vector<char> letters, std::vector<int> score) {
    std::vector<int> letterscount(26, 0);
    for (char c : letters) letterscount[c - 'a']++;
    int n = words.size();
    int maxscore = 0;
    std::vector<int> wordscores(n, 0);
    for (int i = 0; i < n; i++) for (char c : words[i]) wordscores[i] += score[c - 'a'];
    for (int mask = 0; mask < (1 << n); mask++) {
        std::vector<int> remaining = letterscount;
        int currentscore = 0;
        bool possible = true;
        for (int i = 0; i < n && possible; i++) {
            if (mask & (1 << i)) {
                for (char c : words[i]) {
                    int idx = c - 'a';
                    if (remaining[idx] == 0) {
                        possible = false;
                        break;
                    }
                    remaining[idx]--;
                }
                if (possible) {
                    currentscore += wordscores[i];
                }
            }
        }

        if (possible) {
            maxscore = std::max(maxscore, currentscore);
        }
    }
    return maxscore;
}