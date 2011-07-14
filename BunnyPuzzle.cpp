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

class BunnyPuzzle {
    public:
        int theCount(vector <int> bs) {
            if (bs.size() == 2)
                return 2;
            int result = 0;
            for (int i = 0; i < bs.size(); ++i) {

                if (i > 1 && i < bs.size()-2) {
                    if (2*bs[i+1]-bs[i] > bs[i+2])
                        ++result;
                    if (2*bs[i-1]-bs[i] < bs[i-2])
                        ++result;
                } else {
                    if (i == 0) {
                        if (2*bs[i+1]-bs[i] > bs[i+2]) {
                            ++result;
                        }
                    }
                    if (i == 1 && i != bs.size()-2) {
                        ++result;
                        if (2*bs[i+1]-bs[i] > bs[i+2]) {
                            ++result;
                        }
                    }
                    if (i == bs.size()-1) {
                        if (2*bs[i-1]-bs[i] < bs[i-2]) {
                            ++result;
                        }
                    }
                    if (i == bs.size()-2) {
                        ++result;
                        if (2*bs[i-1]-bs[i] < bs[i-2]) {
                            ++result;
                        }
                    }
                }
            }
            return result;
        }
};
