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

class BouncingBalls {
    public:
        double expectedBounces(vector <int> x, int T) {
            int ret = 0;
            sort(x.begin(), x.end());

            for (int i = 0; i < x.size(); ++i) {
                for (int j = i + 1; j < x.size(); ++j) {
                    if (x[j] - x[i] <= 2 * T)
                        ++ret;
                }
            }
            return ret * 0.25;
        }
};
