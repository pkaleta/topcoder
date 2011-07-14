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

const int MAX_W = 50;
const int MAX_H = 50;

class StarAdventure
{
    public:
        int mostStars(vector <string> level) {
            int dp[MAX_W][MAX_W][MAX_W];
            int sums[MAX_H][MAX_W][MAX_W];

            memset(dp, 0, sizeof(dp));

            for (int i = 0; i < level.size(); ++i)
            {
                int tmp[MAX_W];
                memset(tmp, 0, sizeof(tmp));
                tmp[0] = level[i][0];
                for (int j = 1; j < level[i].size(); ++j)
                    tmp[j] = tmp[j-1]+level[i][j];
                for (int j = 0; j < level[i].size(); ++j)
                    for (int k = j+1; k < level[i].size(); ++k)
                        sums[i][j][k] = tmp[k]-tmp[j]+level[i][j];
            }

            for (int y = 0; y < level.size(); ++y)
            {
                for (int i = 0; i < level[0].size(); ++i)
                {
                    for (int j = i+1; j < level[0].size(); ++j)
                    {
                        for (int k = j+1; k < level[0].size(); ++k)
                        {
                            dp[i][j][k] = 
                        }
                    }
                }
            }
        }
};
