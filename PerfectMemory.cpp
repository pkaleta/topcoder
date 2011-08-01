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


class PerfectMemory {
    public:
        int dp[1000000];
        double ret;

        void calc(int moves, int left, double prob) {
            cout << "************* " << moves << " " << left << " " << prob << endl;
            if (left == 0) {
                cout << "koniec: " << moves << " " << prob << endl;
                ret += ((double)moves)*prob;
                return;
            }
//            if (left == 2) {
//                cout << "koniec: " << moves+1 << " " << prob << endl;
//                ret += ((double)(moves+1))*prob;
//                return;
//            }
            for (int i = 1; i <= left-1; ++i) {
                cout << "move: " << moves+i << ": " << i << " " << left-1 << endl;
                double tmp = prob * (((double)i) / ((double)(left-1)));
                calc(moves+i, left-2, tmp);
            }
        }

        double getExpectation(int N, int M) {
            ret = 0.0;
            calc(0, N*M, 1.0);
            return ret;
        }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 2.6666666666666665; verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 4.333333333333334; verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; double Arg2 = 12.392984792984793; verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PerfectMemory ___test;
	___test.run_test(-1);
}
// END CUT HERE
