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


class AmountApproximation {
    public:
        int approximate(int D, int p1, int p2) {
            map<int, bool> sums;
            if (D % p1 == 0 || D % p2 == 0) return D;
            if (p1 < p2) {
                int tmp = p1;
                p1 = p2;
                p2 = tmp;
            }
            int t1 = (D / p1) + 1;
            int s1 = t1 * p1;
            int t2 = 0;
            int s2 = 0;
            int ret = 2000000100;

            while (s1 >= 0) {
                if (sums.find(s1+s2) != sums.end()) break;
                sums[s1+s2] = true;
                ret = min(ret, s1+s2);
                s1 -= p1;
                while (s1+s2 < D) {
                    s2 += p2;
                }
            }
            return ret;
        }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 17; int Arg1 = 7; int Arg2 = 9; int Arg3 = 18; verify_case(0, Arg3, approximate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 17; int Arg1 = 7; int Arg2 = 13; int Arg3 = 20; verify_case(1, Arg3, approximate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 21; int Arg1 = 7; int Arg2 = 13; int Arg3 = 21; verify_case(2, Arg3, approximate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 37; int Arg1 = 9; int Arg2 = 17; int Arg3 = 43; verify_case(3, Arg3, approximate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 287341; int Arg1 = 2345; int Arg2 = 7253; int Arg3 = 287398; verify_case(4, Arg3, approximate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AmountApproximation ___test;
	___test.run_test(-1);
}
// END CUT HERE
