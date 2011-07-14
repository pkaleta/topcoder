#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class NumberLabyrinthDiv2 {
    public:
        static const int INF = 1 << 30;
        int moves[55][55][55];
        bool visited[55][55];
        int sx, sy;
        int fx, fy;
        vector <string> board;
        queue<vector<int> > q;

        void push(int x, int y, int k, int d) {
            vector<int> v;
            v.push_back(x);
            v.push_back(y);
            v.push_back(k);
            v.push_back(d);
            q.push(v);
        }

        int visit(int x0, int y0, int k0, int d0) {
            int x, y, k, dist;

            push(x0, y0, k0, d0);

            while (!q.empty()) {
                vector<int> v = q.front();
                x = v[0]; y = v[1]; k = v[2]; dist = v[3];

                q.pop();

                if (x < 0 || y < 0 || x >= sx || y >= sy) continue;
                if (k < 0) continue;
                if (dist >= moves[y][x][k]) continue;

                if (x == fx && y == fy)
                    return dist;

                moves[y][x][k] = dist;
                if (board[y][x] == '0') continue;

                if (board[y][x] == '.') {
                    for (int d = 1; d <= 9; ++d) {
                        push(x+d, y, k-1, dist+1);
                        push(x-d, y, k-1, dist+1);
                        push(x, y+d, k-1, dist+1);
                        push(x, y-d, k-1, dist+1);
                    }
                } else {
                    int d = board[y][x]-'0';
                    push(x+d, y, k, dist+1);
                    push(x-d, y, k, dist+1);
                    push(x, y+d, k, dist+1);
                    push(x, y-d, k, dist+1);
                }
            }
            return -1;
        }

        int getMinimumNumberOfMoves(vector <string> b, int r1, int c1, int r2, int c2, int K) {
            this->board = b;
            sy = board.size();
            sx = board[0].size();
            fy = r2;
            fx = c2;

            for (int i = 0; i < 55; ++i) {
                for (int j = 0; j < 55; ++j) {
                    for (int k = 0; k < 55; ++k) {
                        moves[i][j][k] = INF;
                    }
                    visited[i][j] = false;
                }
            }

            return visit(c1, r1, K, 0);
        }
};

