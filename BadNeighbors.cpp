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

class BadNeighbors {
    public:

        int t[4][40];

        int maxDonations(vector <int> ds) {
            t[0][0] = ds[0];
            t[1][0] = t[2][0] = t[3][0] = 0;
            for (int i = 1; i < ds.size()-1; ++i) {
                t[0][i] = ds[i]+t[1][i-1];
                t[1][i] = max(t[0][i-1], t[1][i-1]);
            }
            for (int i = 1; i < ds.size(); ++i) {
                t[2][i] = ds[i]+t[3][i-1];
                t[3][i] = max(t[2][i-1], t[3][i-1]);
            }

            int a = max(t[0][ds.size()-2], t[1][ds.size()-2]);
            int b = max(t[2][ds.size()-1], t[3][ds.size()-1]);

            return max(a, b);
        }
};
