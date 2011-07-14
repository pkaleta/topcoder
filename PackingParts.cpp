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

class PackingParts {
    public:
        int pack(vector <int> ps, vector <int> bs) {
            int result = 0;

            int i = 0;
            int j = 0;
            while (i < ps.size() && j < bs.size())
            {
                if (ps[i] <= bs[j])
                {
                    ++result;
                    ++i;
                }
                ++j;
            }

            return result;
        }
};
