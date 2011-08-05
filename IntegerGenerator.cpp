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


class IntegerGenerator {
    public:
        string nextInteger(vector <int> allowed, string current) {
            if (current[0] == '0')
                return "INVALID INPUT";

            vector<int> cur;
            for (int i = 0; i < current.size(); ++i) {
                cur.push_back(current[i]-'0');
            }

            for (int i = 0; i < cur.size(); ++i) {
                bool found = false;
                for (int j = 0; j < allowed.size(); ++j) {
                    if (cur[i] == allowed[j]) {
                        found = true;
                        break;
                    }
                }
                if (!found)
                    return "INVALID INPUT";
            }

            sort(allowed.begin(), allowed.end());
            string a = "9999999999999999";
            bool found = false;
            for (int i = cur.size()-1; i >= 0 && !found; --i) {
                for (int j = 0; j < allowed.size() && !found; ++j) {
                    if (cur[i] < allowed[j]) {
                        for (int k = i+1; k < current.size(); ++k)
                            current[k] = allowed[0]+'0';
                        current[i] = allowed[j]+'0';
                        a = current;
                        found = true;
                    }
                }
            }

            int x;
            int y;
            if (allowed[0] == 0) {
                x = 0; y = allowed[1];
            } else {
                x = allowed[0];
                y = allowed[0];
            }

            string ret;
            ret += y+'0';
            for (int i = 0; i < cur.size(); ++i) {
                ret += x+'0';
            }
            cout << ret << " " << a << endl;
            if (ret.size() < a.size())
                return ret;
            if (ret.size() > a.size())
                return a;
            return min(ret, a);
        }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "16"; string Arg2 = "17"; verify_case(0, Arg2, nextInteger(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 0, 1, 2, 3, 4, 5, 6, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "16"; string Arg2 = "18"; verify_case(1, Arg2, nextInteger(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 3, 5, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "548"; string Arg2 = "INVALID INPUT"; verify_case(2, Arg2, nextInteger(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 5, 3, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "033"; string Arg2 = "INVALID INPUT"; verify_case(3, Arg2, nextInteger(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "999"; string Arg2 = "1000"; verify_case(4, Arg2, nextInteger(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = { 0, 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0"; string Arg2 = "INVALID INPUT"; verify_case(5, Arg2, nextInteger(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = { 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1"; string Arg2 = "11"; verify_case(6, Arg2, nextInteger(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IntegerGenerator ___test;
	___test.run_test(-1);
}
// END CUT HERE
