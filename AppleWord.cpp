#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
using namespace std;

int count[256];

class AppleWord {
    public:
        int minRep(string word) {
            int result = 0;
            if (word.size() < 5)
                return -1;
            else {
                if (word[0] != 'a' && word[0] != 'A')
                    ++result;
                if (word[word.size() - 1] != 'e' && word[word.size() - 1] != 'E')
                    ++result;
                if (word[word.size() - 2] != 'l' && word[word.size() - 2] != 'L')
                    ++result;
                for (int i = 1; i < word.size() - 2; ++i) {
                    if (word[i] != 'p' && word[i] != 'P')
                        ++result;
                }
                return result;
            }
        }
};
