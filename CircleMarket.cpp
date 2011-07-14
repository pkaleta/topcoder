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

class CircleMarket {
    public:
        int makePurchases(vector <int> open, vector <int> close, int travel) {
            int t = 0;
            int pur = 0;
            int i = 0;
            bool mark[100];

            memset(mark, 0, sizeof(mark));

            int m = 0;
            for (int j = 0; j < close.size(); ++j)
                m = max(close[j], m);

            while (t <= m)
            {
                if (t >= open[i] && t <= close[i] && !mark[i])
                {
                    mark[i] = true;
                    ++pur;
                }
                i = (i+1)%open.size();
                t += travel;
            }
            return pur;
        }
};
