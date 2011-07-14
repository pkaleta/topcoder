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

class QuickSort {
    public:
        long long tot;
        long long div;

        long long cost(vector <int> l, int p)
        {
            if (l.size() < 2)
                return 0;

            vector<int> left;
            vector<int> right;

            long long cl = 0;
            long long cr = 0;

            for (int k = 0; k < l.size(); ++k)
            {
                if (l[k] < l[p])
                {
                    left.push_back(l[k]);
                    if (k > p)
                        ++cl;
                }
                else if (l[k] > l[p])
                {
                    right.push_back(l[k]);
                    if (k < p)
                        ++cr;
                }
            }

            tot += cl+cr;
            div += l.size();
            for (int i = 0; i < left.size(); ++i)
            {
                cost(left, i);
            }
            for (int i = 0; i < right.size(); ++i)
            {
                cost(right, i);
            }
            return tot;
        }

        double getEval(vector <int> L) {
            long long result = 0;
            tot = 0;
            div = 0;

            for (int i = 0; i < L.size(); ++i)
            {
                result += cost(L, i);
            }
            return (double)tot/(double)div;
        }
};
