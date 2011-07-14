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

class Desertification {
    public:
        int desertArea(vector <string> island, int T) {
            int desertCells = 0;
            for (int i = 0; i < island.size(); ++i) {
                for (int j = 0; j < island[i].size(); ++j) {
                    if (island[i][j] == 'D')
                        ++desertCells;
                }
            }

            if (desertCells > 0) {
                int t = 0;
                while (t < T && desertCells < island.size() * island[0].size()) {
                    for (int i = 0; i < island.size(); ++i) {
                        for (int j = 0; j < island[i].size(); ++j) {
                            if (island[i][j] == 'F') {
                                if (i-1 >= 0 && island[i-1][j] == 'D') {
                                    island[i][j] = 'd';
                                    ++desertCells;
                                } else if (i+1 < island.size() && island[i+1][j] == 'D') {
                                    island[i][j] = 'd';
                                    ++desertCells;
                                } else if (j-1 >= 0 && island[i][j-1] == 'D') {
                                    island[i][j] = 'd';
                                    ++desertCells;
                                } else if (j+1 < island[i][j+1] && island[i][j+1] == 'D') {
                                    island[i][j] = 'd';
                                    ++desertCells;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < island.size(); ++i) {
                        for (int j = 0; j < island[i].size(); ++j) {
                            if (island[i][j] == 'd')
                                island[i][j] = 'D';
                        }
                    }
                    ++t;
                }
            }
            return desertCells;
        }
};
