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

const int MAXN = 51;

class TheSquareDivTwo {
    public:
        vector <string> solve(vector <string> board) {
            int row[MAXN];
            vector<string> result;

            for (int i = 0; i < board.size(); ++i) {
                string empty(board[i].size(), '.');
                result.push_back(empty);
            }

            memset(row, 0, sizeof(int)*MAXN);
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[i].size(); ++j) {
                    if (board[i][j] == 'C')
                        ++row[i];
                }
            }

            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < row[i]; ++j) {
                    result[board.size() - j - 1][i] = 'C';
                }
            }

            return result;
        }
};
