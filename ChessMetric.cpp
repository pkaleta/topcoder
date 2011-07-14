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

class ChessMetric {
    public:
        static const int MAX_SIZE = 105;
        static const int MAX_MOVES = 55;
        long long dp[MAX_SIZE][MAX_SIZE][MAX_MOVES];

        long long f(int x, int y, int size, int m) {
            if (x < 0 || x > size || y < 0 || y > size)
                return 0;
            if (m < 0)
                return 0;
            if (dp[x][y][m] != -1)
                return dp[x][y][m];

            long long tmp = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx != 0 || dy != 0) {
                        tmp += f(x+dx, y+dy, size, m-1);
                    }
                }
            }
            for (int dx = -2; dx <= 2; ++dx) {
                for (int dy = -2; dy <= 2; ++dy) {
                    if (abs(dx) + abs(dy) == 3) {
                        tmp += f(x+dx, y+dy, size, m-1);
                    }
                }
            }
            dp[x][y][m] = tmp;
            return tmp;
        }

        long long howMany(int size, vector <int> start, vector <int> end, int numMoves) {
            int sx = start[0];
            int sy = start[1];
            int ex = end[0];
            int ey = end[1];

            for (int i = 0; i < MAX_SIZE; ++i) {
                for (int j = 0; j < MAX_SIZE; ++j) {
                    for (int k = 0; k < MAX_MOVES; ++k) {
                        dp[i][j][k] = -1;
                    }
                }
            }

            dp[sx][sy][0] = 1;

            return f(ex, ey, size, numMoves);
        }
};
