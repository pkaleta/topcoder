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

class ChickenOracle {
    public:
        string theTruth(int n, int egg, int lie, int liar) {
            int chicken = n-egg;
            bool e, c;
            e = c = false;

            int a = egg-lie;
            int b = chicken+lie;

            if (a == liar)
                c = true;
            else if (b == liar)
                e = true;

            a = egg+lie;
            b = chicken-lie;

            if (a == liar)
                c = true;
            else if (b == liar)
                e = true;

            if (e && c)
                return "Ambiguous";
            else if (e)
                return "The egg";
            else if (c)
                return "The chicken";
            else
                return "The oracle is a lie";
        }
};
