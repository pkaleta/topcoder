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

class LotteryCheating {
    public:
        static const int max_n = 100005;

        int diffs(string& a, string& b) {
            int result = 0;

            for (int i = 1; i <= b.size(); ++i) {
                result += a[a.size()-i] != b[b.size()-i];
            }
            return result;
        }

        string itoa(long long n) {
            string tmp = "";
            if (n == 0)
                return "0000000000";
            while (n) {
                tmp = (char)((n%10)+'0')+tmp;
                n /= 10;
            }
            while(tmp.size() < 10)
                tmp = "0"+tmp;

            return tmp;
        }

        long long atoi(string n) {
            long long result = 0;

            for (int i = 0; i < n.size(); ++i) {
                result = result*10+(n[i]-'0');
            }

            return result;
        }

        int minimalChange(string id) {
            int n = 0;
            string t[max_n];

            long long c = 0;
            for (c = 0; c*c <= atoi(id); ++c) {
                t[c] = itoa(c*c);
            }
            for (int i = 0; i < id.size(); ++i) {
                n = n*10+id[i]-'0';
            }

            int result = 20;
            for (int i = 0; i < c; ++i) {
                cout << id << ", " << t[i] << ", " << diffs(id, t[i]) << endl;
                result = min(result, diffs(id, t[i]));
            }
            return result;
        }
};

int main() {
    LotteryCheating lc;
    cout << lc.minimalChange("49637") << endl;
    return 0;
}
