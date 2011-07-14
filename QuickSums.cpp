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

const int MAXLEN = 15;
const int MAXSUM = 105;
const int INFTY = MAXSUM*3;

int dp[MAXLEN][MAXSUM];

class QuickSums {
    public:
        int minSums(string numbers, int sum) {
            memset(dp, -1, sizeof(dp));
            dp[0][numbers[0]-'0'] = 0;

            for (int i = 1; i < numbers.size(); ++i) {
                for (int j = 0; j <= i; ++j) {
                    int tmp = 0;
                    for (int k = j+1; k <= i; ++k) {
                        tmp = tmp*10+(numbers[k]-'0');
                    }
                    for (int k = 0; k < MAXSUM; ++k) {
                        if (k+tmp <= MAXSUM) {
                            if (dp[j][k] >= 0 && \
                                    (dp[i][k+tmp] < 0 || dp[j][k]+1 < dp[i][k+tmp])) {
                                dp[i][k+tmp] = dp[j][k];
                                if (numbers[i] != '0')
                                    dp[i][k+tmp]++;
                            }
                        }
                    }
                }
            }

            printf("    ");
            for (int i = 0; i < numbers.size(); ++i)
                printf("%5c", numbers[i]);
            printf("\n");
            for (int j = 0; j <= sum; ++j) {
                printf("%2d: ", j);
                for (int i = 0; i < numbers.size(); ++i) {
                    printf("%5d", dp[i][j]);
                }
                printf("\n");
            }

            return dp[numbers.size()-1][sum];
        }
};
