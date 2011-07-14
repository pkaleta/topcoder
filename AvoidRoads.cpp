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

class AvoidRoads {
    public:
        static const int MAX = 105;
        bool t[MAX][MAX][2];
        long long dp[MAX][MAX];

        long long numWays(int w, int h, vector <string> bad) {
            memset(t, 1, sizeof(t));
            memset(dp, 0, sizeof(dp));

            for (int i = 0; i < bad.size(); ++i) {
                stringstream ss(bad[i]);
                int a, b, c, d;

                ss >> a >> b >> c >> d;
                if (a < c) {
                    t[b][a][0] = false;
                } else if (b < d) {
                    t[b][a][1] = false;
                } else if (c < a) {
                    t[d][c][0] = false;
                } else if (d < b) {
                    t[d][c][1] = false;
                }
            }

            dp[0][0] = 1;

            for (int i = 0; i <= h; ++i) {
                for (int j = 0; j <= w; ++j) {
                    if (t[i][j][1])
                        dp[i+1][j] += dp[i][j];
                    if (t[i][j][0])
                        dp[i][j+1] += dp[i][j];
                }
            }

            for (int i = 0; i <= h; ++i) {
                cout << i << ": ";
                for (int j = 0; j <= w; ++j) {
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }

            return dp[h][w];
        }
};
