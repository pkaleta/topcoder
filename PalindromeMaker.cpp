#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <list>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class PalindromeMaker {
    public:
        string make(string baseString) {
            int count[256];
            memset(count, 0, sizeof(count));

            for (int i = 0; i < baseString.size(); ++i) {
                count[(int) baseString[i]]++;
            }

            int odd = 0;
            string center = "";
            for (int i = 0; i < 256; ++i) {
                if (count[i] & 1) {
                    --count[i];
                    center += i;
                    ++odd;
                }
            }
            if (odd > 1)
                return "";

            string a, b;

            for (int i = 0; i < 256; ++i) {
                string tmp;
                if (count[i]) {
                    tmp = string(count[i] / 2, i);
                }
                a = a + tmp;
                b = tmp + b;
            }

            return a + center + b;
        }
};
