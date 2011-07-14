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

class TheFansAndMeetingsDivTwo {
    public:
        double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB) {
            double a, b, result = 0.0;
            int size = minJ.size();

            for (int r = 1; r <= 50; ++r) {
                a = b = 0.0;
                for (int i = 0; i < size; ++i) {
                    if (minJ[i] <= r && maxJ[i] >= r) {
                        a += (1/(double)size) * (1/(double)(maxJ[i]-minJ[i]+1));
                    }
                    if (minB[i] <= r && maxB[i] >= r) {
                        b += (1/(double)size) * (1/(double)(maxB[i]-minB[i]+1));
                    }
                }
                result += a * b;
            }
            return result;
        }
};
