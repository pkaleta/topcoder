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

const int MAXCOL = 30;
const int MAXLEN = 55;

int dp[MAXCOL][MAXLEN][MAXLEN];
int s[MAXLEN];

class StripePainter {
    public:
        int f(int c, int l, int r) {
            int& res = dp[c][l][r];
            if (res != -1)
                return res;

            for (; l <= r && s[l] == c; ++l);
            if (l > r)
                return res = 0;

            res = r-l+1;
            for (int i = l; i <= r; ++i) {
                res = min(res, 1+f(s[l], l, i)+f(c, i+1, r));
            }
            return res;
        }

        int minStrokes(string stripes) {
            memset(dp, -1, sizeof(dp));
            for (int i = 0; i < stripes.size(); ++i)
                s[i] = stripes[i]-'A'+1;
            return f(0, 0, stripes.size()-1);
        }
};
