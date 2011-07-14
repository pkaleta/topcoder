#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <list>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;

class SoldierLabeling {
    public:
        int count(int n, int l, int u) {
            int a, b;

            a = 1;
            for (int i = 0; i < l - 1; ++i)
                a *= 10;

            b = 9;
            for (int i = 0; i < u - 1; ++i) {
                b = b * 10 + 9;
            }
            cout << a << ", " << b << endl;
            if (a > n)
                return 0;
            b = min(b, n);
            return b - a + 1;
        }
};
