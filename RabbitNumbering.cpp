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

const long long MOD = 1000000007;

class RabbitNumbering {
    public:
        int theCount(vector <int> m) {
            long long result = 1;
            sort(m.begin(), m.end());
            for (int i = 0; i < m.size(); ++i) {
                result = (result*(m[i]-i))%MOD;
            }
            return result;
        }
};
