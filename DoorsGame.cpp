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

class DoorsGame {
    public:
        int determineOutcome(string doors, int trophy) {
            char j[256];
            char g[256];
            memset(j, 0, sizeof(j));
            memset(g, 0, sizeof(g));

            for (int i = 0; i < doors.size(); ++i)
            {
                if (i < trophy)
                    j[(int)doors[i]] = true;
                else
                    g[(int)doors[i]] = true;
            }

            vector<char> common;
            vector<char> a;
            vector<char> b;

            for (int i = 0; i < 256; ++i)
            {
                if (j[i] && g[i])
                    common.push_back(i);
                else if (j[i])
                    a.push_back(i);
                else if (g[i])
                    b.push_back(i);
            }

            cout << common.size() << " " << a.size() << " " << b.size() << endl;
            int result = 0;
            int as = a.size();
            int bs = b.size();
            int cs = common.size();
            bool turn = true;
            while (1) {
                if (as == 0 && bs == 0)
                    return 0;
                if (cs == 0)
                    if (as == 0)
                        return result;
                    else if (bs == 0)
                        return -result;

                ++result;
                if (turn) {
                    if (as == 0) {
                        --cs;
                    } else {
                        --as;
                    }
                } else {
                    if (bs == 0) {
                        --cs;
                    } else {
                        --bs;
                    }
                }
                turn = !turn;
            }
        }
};
