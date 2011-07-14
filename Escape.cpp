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

const int MAX = 505;

struct Node {
    int x, y;
    int damage;
};

class Escape {
    public:
        int lowest(vector <string> harmful, vector <string> deadly) {
            int m[MAX][MAX];
            int x1, x2, y1, y2;
            bool visited[MAX][MAX];
            int damage[MAX][MAX];
            queue<Node> q;

            memset(m, 0, sizeof(m));
            memset(visited, 0, sizeof(visited));

            for (int i = 0; i < harmful.size(); ++i) {
                sscanf(harmful[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
                for (int a = min(y1, y2); a <= max(y1, y2); ++a) {
                    for (int b = min(x1, x2); b <= max(x1, x2); ++b) {
                        m[a][b] = 1;
                    }
                }
            }
            for (int i = 0; i < deadly.size(); ++i) {
                sscanf(deadly[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
                for (int a = min(y1, y2); a <= max(y1, y2); ++a) {
                    for (int b = min(x1, x2); b <= max(x1, x2); ++b) {
                        m[a][b] = 2;
                    }
                }
            }

            Node start;
            start.x = 0;
            start.y = 0;
            start.damage = 0;
            for (int i = 0; i < MAX; ++i) {
                for (int j = 0; j < MAX; ++j) {
                    damage[i][j] = 1000000;
                }
            }
            q.push(start);
            damage[0][0] = 0;

            while (!q.empty()) {
                Node cur = q.front();
                q.pop();

                if (cur.x < 0 || cur.x > 500 ||
                        cur.y < 0 || cur.y > 500)
                    continue;

                damage[cur.x][cur.y] = min(damage[cur.x][cur.y], cur.damage);

                if (visited[cur.x][cur.y])
                    continue;
                visited[cur.x][cur.y] = true;

                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (abs(dx) + abs(dy) == 1) {
                            int nx = cur.x + dx;
                            int ny = cur.y + dy;
                            if (m[ny][nx] < 2) {
                                Node n;
                                n.x = nx;
                                n.y = ny;
                                n.damage = damage[cur.x][cur.y] + m[cur.y][cur.x];
                                q.push(n);
                            }
                        }
                    }
                }
            }
            if (damage[500][500] == 1000000)
                return -1;
            else
                return damage[500][500];
        }
};
