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

class MatrixGame {
    public:
        vector <string> getMinimal(vector <string> m) {
            int count[10];
            int mrow = -1;
            int mcount = 20;

            for (int i = 0; i < m.size(); ++i) {
                count[i] = 0;
                for (int j = 0; j < m[i].size(); ++j) {
                    count[i] += m[i][j] == '1';
                }
                if (count[i] < mcount) {
                    mrow = i;
                    mcount = count[i];
                }
            }

            string tmp = m[mrow];
            m[mrow] = m[0];
            m[0] = tmp;

            for (int i = 0; i < m.size(); ++i) {
                for (int j = 0; j < m[i].size(); ++j) {
                    if (m[i][j] == '0') {
                        for (int k = 0; k < j; ++k) {
                            if (m[i][k] == '1') {
                                int possible = true;
                                for (int l = 0; l < i; ++l) {

                                }

                                if (possible) {
                                    for (int l = 0; l < m.size(); ++l) {
                                        char c = m[i][k];
                                        m[i][k] = m[i][j];
                                        m[i][j] = c;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return m;
        }
};
