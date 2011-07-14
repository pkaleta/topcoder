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

class TurretPlacement {
    public:
        long long calc(int x1, int y1, int x2, int y2) {
            int dx = abs(x2-x1);
            int dy = abs(y2-y1);
            double d = sqrt(dx*dx+dy*dy);
            long long p = (long long)(d*2);
            return p*(p-1)/2;
        }

        long long count(vector <int> x, vector <int> y) {
            long long result = 0;

            for (int i = 0; i < x.size(); ++i) {
                for (int j = i+1; j < x.size(); ++j) {
                    result += calc(x[i], y[i], x[j], y[j]);
                }
            }

            return result;
        }
};
