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

class Nisoku {
    public:
        double f(vector<double> cs) {
            if (cs.size() == 2)
                return max(cs[0]*cs[1], cs[0]+cs[1]);

            double m = 0;

            for (int i = 0; i < cs.size(); ++i) {
                for (int j = i+1; j < cs.size(); ++j) {
                    vector<double> tmp = cs;
                    tmp.erase(tmp.begin()+i);
                    tmp.erase(tmp.begin()+j-1);
                    double x = f(tmp);
                    double a = (cs[i]*cs[j])*x;
                    double b = (cs[i]*cs[j])+x;
                    double c = (cs[i]+cs[j])*x;
                    double d = (cs[i]+cs[j])+x;
                    m = max(m, max(a, max(b, max(c, d))));
                }
            }
            return m;
        }

        double theMax(vector <double> cs) {
            return f(cs);
        }
};

int main() {
    vector<double> x;
    x.push_back(8.26);
    x.push_back(7.54);
    x.push_back(3.2567);

    Nisoku n;
    cout << n.theMax(x) << endl;
    return 0;
}
