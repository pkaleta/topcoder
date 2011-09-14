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


class NetworkXOneTimePad {
    public:
        string xor1(string c, string p) {
            string ret;
            for (int i = 0; i < c.size(); ++i) {
                if (c[i] != p[i]) ret += '1';
                else ret += '0';
            }
            return ret;
        }

        int crack(vector <string> ps, vector <string> cs) {
            map<string, int> keys;

            for (int i = 0; i < cs.size(); ++i) {
                for (int j = 0; j < ps.size(); ++j) {
                    string s = xor1(cs[i], ps[j]);
                    keys[s]++;
                }
            }

            int ret = 0;
            for (map<string, int>::iterator it = keys.begin(); it != keys.end(); ++it) {
//                cout << it-> first << " " << it->second << endl;
                if (it->second == cs.size()) ++ret;
            }
            return ret;
        }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"101", "010"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, crack(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00", "01", "10", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "01", "10", "11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, crack(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, crack(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "111", "010", "101", "110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"011", "100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, crack(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NetworkXOneTimePad ___test;
	___test.run_test(-1);
}
// END CUT HERE
