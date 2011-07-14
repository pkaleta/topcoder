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

class ColoringRectangle {
    public:

        double calc(int dia, int h) {
            double r = ((double)dia) / 2.0f;
            double hh = ((double)h) / 2.0f;
            return sqrt(r * r - hh * hh);
        }

        int chooseDisks(int w, int h, vector <int> r, vector <int> b) {
            sort(r.rbegin(), r.rend());
            sort(b.rbegin(), b.rend());

            int result = 0;
            int i = 0, j = 0;
            bool red;
            if (r[0] >= b[0])
                red = true;
            else
                red = false;

            double dist = 0;

            while (dist < w) {
                if (red) {
                    if (i >= r.size() || r[i] < h)
                        return -1;
                    dist += 2*calc(r[i++], h);
                    result++;
                } else {
                    if (j >= b.size() || b[j] < h)
                        return -1;
                    dist += 2*calc(b[j++], h);
                    result++;
                }
                red = !red;
            }
            return result;
        }
};
