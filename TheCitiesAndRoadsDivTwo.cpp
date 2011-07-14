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

class TheCitiesAndRoadsDivTwo {
    public:
        vector<int> sizes;
        bool visited[10];

        void dfs(int n, vector<string> map, int& num) {
            if (!visited[n]) {
                ++num;
                visited[n] = true;
                for (int i = 0; i < map.size(); ++i) {
                    if (map[n][i] == 'Y' && !visited[i]) {
                        dfs(i, map, num);
                    }
                }
            }
        }

        int find(vector <string> map) {

            memset(visited, 0, sizeof(visited));

            for (int i = 0; i < map.size(); ++i) {
                if (!visited[i]) {
                    int num = 0;
                    dfs(i, map, num);
                    sizes.push_back(num);
                }
            }
            if (sizes.size() == 1)
                return 1;

            int result = 1;
            for (int i = 0; i < sizes.size(); ++i)
                result *= sizes[i];
            return result;
        }
};
