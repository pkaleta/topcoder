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

const int MAXN = 55;

class ZigZag {
    public:
        int longestZigZag(vector<int> seq) {
            int l[MAXN], g[MAXN];
            int result = 0;


            for (int i = 0; i < MAXN; ++i)
                l[i] = g[i] = 1;

            for (int i = 0; i < seq.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    if (seq[i] < seq[j]) {
                        l[i] = max(g[j] + 1, l[i]);
                    } else if (seq[i] > seq[j]) {
                        g[i] = max(l[j] + 1, g[i]);
                    }
                }
            }

            for (int i = 0; i < seq.size(); ++i) {
                result = max(result, max(l[i], g[i]));
            }
            return result;
        }
};
