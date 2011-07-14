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

class OptimalQueues {
    private:
        static bool cmp (int i, int j) { return (i > j); }
    public:

        int minWaitingTime(vector <int> clientArrivals, int tellerCount, int serviceTime) {
            int result = 0;

            sort(clientArrivals.begin(), clientArrivals.end(), cmp);
            for (int i = 0, m = 1; i < clientArrivals.size(); i += tellerCount, ++m)
            {
                for (int j = 0; j < tellerCount && i+j < clientArrivals.size(); ++j)
                {
                    int tmp;
                    if ((tmp = clientArrivals[i+j]+m*serviceTime) > result)
                        result = tmp;
                }
            }
            return result;
        }
};
