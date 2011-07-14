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

class LotteryTicket {
    public:
        string buy(int p, int b1, int b2, int b3, int b4) {
            if (b1 == p || b2 == p || b3 == p || b4 == p ||
                    b1+b2 == p || b1+b3 == p || b1+b4 == p ||
                    b2+b3 == p || b2+b4 == p || b3+b4 == p ||
                    b1+b2+b3 == p || b1+b3+b4 == p || b2+b3+b4 == p ||
                    b1+b2+b4 == p || b1+b2+b3+b4 == p)
                return "POSSIBLE";
            else
                return "IMPOSSIBLE";
        }
};
