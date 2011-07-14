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

const int MAXN = 55;

class FuzzyLife {
    public:

        int how_many_alive(int x, int y, vector<string>& grid) {
            int alive = 0;

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if ((dx != 0 || dy != 0) && x+dx < grid[0].size() && x+dx >= 0 &&
                            y+dy < grid.size() && y+dy >= 0) {
                        alive += grid[y+dy][x+dx]-'0';
                    }
                }
            }
            return alive;
        }

        int test(int x, int y, vector<string>& grid) {
            int alive = how_many_alive(x, y, grid);

            if (grid[y][x] == '0') {
                if (alive == 3)
                    return 1;
                else
                    return 0;
            } else {
                if (alive >= 2 && alive <= 3)
                    return 1;
                else return 0;
            }
        }

        int set(int x, int y, char c, vector<string>& grid) {
            int result = 0;

            grid[y][x] = c;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if ((dx != 0 || dy != 0) && x+dx < grid[0].size() && x+dx >= 0 &&
                            y+dy < grid.size() && y+dy >= 0) {
                        result += test(x+dx, y+dy, grid);
                    }
                }
            }
            return result;
        }

        void calc(int x, int y, vector<string>& grid) {
            int a = set(x, y, '0', grid);
            int b = set(x, y, '1', grid);

            if (a > b)
                grid[y][x] = '0';
            else
                grid[y][x] = '1';
        }

        int play(vector<string>& grid) {
            int result = 0;


            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[i].size(); ++j) {
                    int alive = how_many_alive(j, i, grid);

                    if (grid[j][i] == '0') {
                        if (alive == 3)
                            ++result;
                    } else {
                        if (alive >= 2 && alive <= 3)
                            ++result;
                    }
                }
            }

            return result;
        }

        int survivingCells(vector <string> grid) {
            vector<string> G;

            for (int i = 0; i <= grid.size()+1; ++i) {
                string s = "";
                for (int j = 0; j <= grid[0].size()+1; ++j) {
                    s += "0";
                }
                G.push_back(s);
            }

            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[i].size(); ++j) {
                    G[i+1][j+1] = grid[i][j];
                }
            }


            for (int i = 0; i < G.size(); ++i) {
                for (int j = 0; j < G[i].size(); ++j) {
                    if (G[i][j] == '?') {
                        calc(j, i, G);
                    }
                }
            }

            return play(G);
        }
};

int main()
{
    FuzzyLife l;
    vector<string> grid;

    grid.push_back("?11?");
    grid.push_back("0110");
    grid.push_back("1000");
    grid.push_back("?11?");
    cout << l.survivingCells(grid) << endl;

    return 0;
}
