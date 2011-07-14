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

struct Node {
    pair<int, int> p1, p2;
    int steps;
};

class PathFinding {
    public:
        int minTurns(vector <string> board) {
            const int MAX_N = 25;
            queue<Node> q;
            bool visited[MAX_N][MAX_N][MAX_N][MAX_N];

            pair<int, int> p1, p2;

            memset(visited, 0, sizeof(visited));

            Node n;
            for (int i = 0; i < board.size(); ++i)
                for (int j = 0; j < board[i].size(); ++j) {
                    if (board[i][j] == 'A') {
                        p1 = make_pair(j, i);
                    } else if (board[i][j] == 'B') {
                        p2 = make_pair(j, i);
                    }
                }

            n.p1 = p1;
            n.p2 = p2;
            n.steps = 0;
            q.push(n);

            while (!q.empty()) {
                Node cur = q.front();
                q.pop();

                if (cur.p1.first < 0 || cur.p1.first >= board[0].size() ||
                        cur.p1.second < 0 || cur.p1.second >= board.size() ||
                        cur.p2.first < 0 || cur.p2.first >= board[0].size() ||
                        cur.p2.second < 0 || cur.p2.second >= board.size())
                    continue;

                if (cur.p1.first == cur.p2.first && cur.p1.second == cur.p2.second)
                    continue;

                if (cur.p1.first == p2.first && cur.p1.second == p2.second &&
                        cur.p2.first == p1.first && cur.p2.second == p1.second)
                    return cur.steps;

                if (visited[cur.p1.first][cur.p1.second][cur.p2.first][cur.p2.second])
                    continue;

                if (board[cur.p1.second][cur.p1.first] == 'X' ||
                        board[cur.p2.second][cur.p2.first] == 'X')
                    continue;

                visited[cur.p1.first][cur.p1.second][cur.p2.first][cur.p2.second] = true;

                for (int d1x = -1; d1x <= 1; ++d1x) {
                    for (int d1y = -1; d1y <= 1; ++d1y) {
                        for (int d2x = -1; d2x <= 1; ++d2x) {
                            for (int d2y = -1; d2y <= 1; ++d2y) {
                                pair<int, int> np1, np2;
                                np1.first = cur.p1.first + d1x;
                                np1.second = cur.p1.second + d1y;
                                np2.first = cur.p2.first + d2x;
                                np2.second = cur.p2.second + d2y;
                                if (np1.first == cur.p2.first && np1.second == cur.p2.second &&
                                        np2.first == cur.p1.first && np2.second == cur.p1.second)
                                    continue;

                                Node nn;
                                nn.p1 = np1;
                                nn.p2 = np2;
                                nn.steps = cur.steps + 1;
                                q.push(nn);
                            }
                        }
                    }
                }
            }
            return -1;
        }
};
