#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstring>


using namespace std;
const int MAX = 100005;


class CompositeSmash {
    public:
        vector<pair<int, int> > divs[MAX];
        map<int, bool> dp;

        void findDivs(int n) {
            for (int i = 2; i*i <= n; ++i) {
                if (n % i == 0) {
                    divs[n].push_back(make_pair(i, n/i));
                }
            }
        }

        bool calc(int n, int target) {
            if (n == target)
                return true;
            if (n < target)
                return false;
            if (divs[n].size() == 0)
                return false;

            if (dp.find(n) != dp.end())
                return dp[n];

            bool ret = true;
            for (int i = 0; i < divs[n].size(); ++i) {
                int a = divs[n][i].first;
                int b = divs[n][i].second;
                if (a == target || b == target) {
                    continue;
                } else {
//                    cout << a << " " << b << endl;
                    ret = ret && (calc(a, target) || calc(b, target));
                }
            }
//            cout << "*******" << n << " " << target << "result: " << ret << endl;

            dp[n] = ret;
            return ret;
        }

        string thePossible(int n, int target) {
            memset(divs, 0, sizeof(divs));
            for (int i = 2; i <=n; ++i)
                findDivs(i);

            if (calc(n, target))
                return "Yes";
            else
                return "No";
        }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 517; int Arg1 = 47; string Arg2 = "Yes"; verify_case(0, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 4; string Arg2 = "Yes"; verify_case(1, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 6; string Arg2 = "No"; verify_case(2, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "No"; verify_case(3, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; string Arg2 = "Yes"; verify_case(4, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 5858; int Arg1 = 2; string Arg2 = "Yes"; verify_case(5, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 81461; int Arg1 = 2809; string Arg2 = "No"; verify_case(6, Arg2, thePossible(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 65536; int Arg1 = 256; string Arg2 = "No"; verify_case(7, Arg2, thePossible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CompositeSmash ___test;
	___test.run_test(-1);
}
// END CUT HERE
