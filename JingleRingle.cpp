#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

bool myfunction (int i, int j) { return (i > j); }

class JingleRingle {
    public:
        int profit(vector <int> buy, vector <int> sell, int tax) {
            int result = 0;

            sort(buy.begin(), buy.end(), myfunction);
            sort(sell.begin(), sell.end());

            int i = 0;

            while (i < buy.size() && i < sell.size()) {
                int tmp = buy[i]-sell[i]-(int)floor((double)(buy[i]*tax)/100.0);
                if (tmp < 0)
                    break;
                result += tmp;
                ++i;
            }
            return result;
        }
};
