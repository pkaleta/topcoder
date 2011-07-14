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
        int dp[MAX_SIZE][MAX_SIZE][MAX_MOVES];
        queue<vector<int> > q;

        void push(int x, int y, int m, int size, int numMoves) {
            for (int dx = -1; dx <= 1; dx += 1) {
                for (int dy = -1; dy <= 1; dy += 1) {
                    if (dx != 0 || dy != 0) {
                        int nx = x+dx; int ny = y+dy;
                        if (nx >= 0 && nx < size && ny >= 0 && ny < size && m <= numMoves) {
                            dp[nx][ny][m] += dp[x][y][m-1];
                            vector<int> v;
                            v.push_back(x); v.push_back(y);
                            v.push_back(x+dx); v.push_back(y+dy);
                            v.push_back(1);
                            q.push(v);
                        }
                    }
                }
            }
            for (int dx = -2; dx <= 2; ++dx) {
                for (int dy = -2; dy <= 2; ++dy) {
                    if (dx != 0 && dy != 0) {
                        int nx = x+dx; int ny = y+dy;
                        if (nx >= 0 && nx < size && ny >= 0 && ny < size && m <= numMoves) {
                            dp[nx][ny][m] += dp[x][y][m-1];
                            vector<int> v;
                            v.push_back(x); v.push_back(y);
                            v.push_back(x+dx); v.push_back(y+dy);
                            v.push_back(1);
                            q.push(v);
                        }
                    }
                }
            }
        }

        long long howMany(int size, vector <int> start, vector <int> end, int numMoves) {
            int sx = start[0];
            int sy = start[1];
            int ex = end[0];
            int ey = end[1];

            memset(dp, 0, sizeof(int)*MAX_SIZE*MAX_SIZE*MAX_MOVES);

            dp[sx][sy][0] = 1;

            push(sx, sy, 1, size, numMoves);

            while (!q.empty()) {
                vector<int> tmp = q.front();
                q.pop();
                int px = tmp[0];
                int py = tmp[1];
                int x = tmp[2];
                int y = tmp[3];
                int m = tmp[4];
                if (x >= 0 && x < size && y >= 0 && y < size && m < numMoves) {
                    //cout << x << ", " << y << endl;
                    push(x, y, m+1, size, numMoves);
                }
            }
            return dp[ex][ey][numMoves];
        }
};
