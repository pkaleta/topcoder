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

class NumberNeighbours {
    public:
        bool check(int a, int b) {
            int da[10], db[10];
            memset(da, 0, sizeof(da));
            memset(db, 0, sizeof(db));
            while (a) {
                da[a%10]++;
                a/=10;
            }
            while (b) {
                db[b%10]++;
                b/=10;
            }
            for (int i = 1; i < 10; ++i) {
                if (da[i] != db[i])
                    return false;
            }
            return true;
        }

        int numPairs(vector <int> ns) {
            int result = 0;
            for (int i = 0; i < ns.size(); ++i) {
                for (int j = i+1; j < ns.size(); ++j) {
                    if (check(ns[i], ns[j]))
                        ++result;
                }
            }
            return result;
        }
};
