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

class TheQuestionsAndAnswersDivTwo {
    public:
        int find(vector <string> qs) {
            bool mark[10];
            int num = 0;

            memset(mark, 0, sizeof(bool) * 10);

            for (int i = 0; i < qs.size(); ++i) {
                if (!mark[i]) {
                    mark[i] = true;
                    ++num;

                    for (int j = 0; j < qs.size(); ++j) {
                        if (i != j && !mark[j]) {
                            if (qs[i].compare(qs[j]) == 0) {
                                mark[j] = true;
                            }
                        }
                    }
                }
            }
            return (int) pow((double)2, (double)num);
        }
};
