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

class grafixMask {

    public:
        vector<int> result;
        bool map[400][600];
        stack<pair<int, int> > s;


        vector <int> sortedAreas(vector <string> rs) {

            memset(map, 0, sizeof(bool) * 400 * 600);

            for (int i = 0; i < rs.size(); ++i) {
                int x1, y1, x2, y2;
                sscanf(rs[i].c_str(), "%d%d%d%d", &y1, &x1, &y2, &x2);
                for (int y = y1; y <= y2; ++y) {
                    for (int x = x1; x <= x2; ++x) {
                        map[y][x] = true;
                    }
                }
            }
            for (int y = 0; y < 400; ++y) {
                for (int x = 0; x < 600; ++x) {
                    if (!map[y][x]) {
                        s.push(make_pair(x, y));
                        result.push_back(dfs());
                    }
                }
            }
            sort(result.begin(), result.end());
            return result;
        }

        int dfs() {
            int result = 0;
            while (!s.empty()) {
                pair<int, int> p = s.top();
                s.pop();
                int x = p.first;
                int y = p.second;
                if (x >= 0 && x < 600 && y >= 0 && y < 400 && !map[y][x]) {
                    map[y][x] = true;
                    s.push(make_pair(x-1, y));
                    s.push(make_pair(x, y-1));
                    s.push(make_pair(x+1, y));
                    s.push(make_pair(x, y+1));
                    ++result;
                }
            }
            return result;
        }
};
