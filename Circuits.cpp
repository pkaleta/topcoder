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

const int MAX_N = 55;

class Circuits {
    public:
        int map[MAX_N][MAX_N];
        bool visited[MAX_N];
        int memo[MAX_N];

        int dfs(int v, int n) {
            visited[v] = true;
            for (int i = 0; i < n; ++i) {
                if (map[v][i]) {
                    if (!visited[i]) {
                        memo[v] = map[v][i] + dfs(i, n);
                    }
                }
            }
            return memo[v];
        }

        int howLong(vector <string> connects, vector <string> costs) {
            int result = 0;

            memset(map, 0, sizeof(int) * MAX_N * MAX_N);
            memset(visited, 0, sizeof(int) * MAX_N);
            memset(memo, 0, sizeof(int) * MAX_N);

            for (int i = 0; i < connects.size(); ++i) {
                string s;
                stringstream vstream(connects[i]);
                stringstream cstream(costs[i]);
                while (getline(vstream, s, ' ')) {
                    int j = atoi(s.c_str());
                    getline(cstream, s, ' ');
                    int cost = atoi(s.c_str());
                    map[i][j] = cost;
                }
            }
            for (int i = 0; i < connects.size(); ++i) {
                if (!visited[i]) {
                    int tmp = dfs(i, connects.size());
                    result = max(result, tmp);
                }
            }
            return result;
        }
};
