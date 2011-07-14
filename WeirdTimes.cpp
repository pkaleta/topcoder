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

class WeirdTimes {
    public:
        const static int max_n = 55;
        const static int max_h = 23;

        vector <int> hourValues(vector <int> mv, int k) {
            vector<int> result;
            int t[max_n];
            int max = 0;

            t[0] = 0;
            for (int i = 1; i < mv.size(); ++i) {
                t[i] = t[i-1];
                if (mv[i] <= mv[i-1]) {
                    ++t[i];
                }
            }

            long long dp[max_n][max_h+1];
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i <= max_h-t[mv.size()-1]; ++i) {
                dp[mv.size()-1][t[mv.size()-1]+i] = i;
            }
            for (int i = mv.size()-1; i >= 0; --i) {
                for (int j = 0; j <= max_h-t[i]; ++j) {
                    for (int k = t[i+1]+j; k <= max_h; ++k) {
                        dp[i][j] += dp[i+1][k];
                    }
                }
            }
            bool flag = false;
            int i, j;
            for (i = mv.size()-2; i >= 0; --i) {
                for (j = 1; j <= max_h-t[i]; ++j) {
                    if (dp[i][j] > k) {
                        flag = true;
                    }
                }
            }
            for (int i = 0; i <= max_h; ++i) {
                for (int j = 0; j < mv.size(); ++j) {
                    printf("%5lld", dp[j][i]);
                }
                printf("\n");
            }
            //if (!flag) {
            //    result.push_back(-1);
            //} else {
            //    t[i--] += j;
            //    int tmp = 0;
            //    while (1) {
            //        if (k == 0) {
            //            for (int i = 0; i < )
            //        } else {
            //            if (dp[i][j] <= k) {
            //                k -= dp[i][j];
            //            }
            //        }
            //    }
            //}
            return result;
        }
};
