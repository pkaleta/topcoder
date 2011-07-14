#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

class TheLuckyGameDivTwo {
    public:
        static const int MAX = 5000;

        int t[MAX];

        bool check(int n) {
            while (n) {
                int d = n%10;
                n /= 10;

                if (d != 4 && d != 7) {
                    return false;
                }
            }
            return true;
        }


        int find(int a, int b, int jLen, int bLen) {
            int ret;

            memset(t, 0, sizeof(t));

            t[a] = check(a);
            for (int i = a+1; i <= b; ++i) {
                t[i] = t[i-1]+check(i);
            }

            ret = -1;
            for (int i = a-1; i <= b-jLen; ++i) {
                int aa = i;
                int bb = i+jLen;

                int cur = 1000005;
                for (int j = aa; j <= bb-bLen; ++j) {
                    int tmp = t[j+bLen]-t[j];
                    cur = min(cur, tmp);
                }
                ret = max(ret, cur);
            }

            return ret;
        }
};
