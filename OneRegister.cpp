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

class OneRegister {
    public:
        string res;
        bool res_flag;
        bool found;
        void calc(long long n, long long t, string s, bool flag)
        {
            if (n == t)
            {
                if (!found || (s.size() < res.size() || (s.size() == res.size() && s.compare(res) < 0)))
                {
                    res_flag = flag;
                    res = s;
                }
                found = true;
            }
            if (n > t)
                return;
            calc(n*2, t, s+"+", flag);
            if (n != 1)
                calc(n*n, t, s+"*", flag);
        }

        string getProgram(int s, int t) {
            res = "";
            found = false;
            calc(1, t, "", true);
            calc(s, t, "", false);
            if (!found)
                return ":-(";
            if (res_flag == true)
                return "/"+res;
            else
                return res;
        }
};
