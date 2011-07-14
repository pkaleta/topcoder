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

class TrappingRabbit {
    public:
        int findMinimumTime(vector <int> x, vector <int> y) {
            int res = 10000000;
            for (int i = 0; i < x.size(); ++i) {
                if (x[i] + y[i] -2 < res)
                    res = x[i] + y[i] - 2;
            }
            return res;
        }
};
