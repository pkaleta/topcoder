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
const int MAX_C = 55;
const int MAX_R = 55;
const int MAX_VAL = 55;


class RowsOrdering {
    public:
        int count[MAX_C][MAX_VAL];

        int toNum(char c) {
            if (c >= 'a' && c <= 'z')
                return c-'a'+1;
            return 26+c-'A'+1;
        }

        int order(vector<string> rows2) {
            vector<vector<int> > rows;
            for (int i = 0; i < rows2.size(); ++i) {
                vector<int> row;
                for (int j = 0; j < rows2[i].size(); ++j)
                    row.push_back(toNum(rows2[i][j]));
                rows.push_back(row);
            }

//            for (int i = 0; i < rows.size(); ++i) {
//                for (int j = 0; j < rows[i].size(); ++j) {
//                    cout << rows[i][j] << " ";
//                }
//                cout << endl;
//            }

            for (int i = 0; i < rows[0].size(); ++i) {
                for (int j = 0; j < rows.size(); ++j) {
                    count[i][rows[j][i]]++;
                }
            }

//            for (int i = 0; i < rows[0].size(); ++i) {
//                cout << count[i][2] << endl;
//            }


        }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bb", "cb", "ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(0, Arg1, order(Arg0)); }
	void test_case_1() { string Arr0[] = {"abcd", "ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 127553; verify_case(1, Arg1, order(Arg0)); }
	void test_case_2() { string Arr0[] = {"Example", "Problem"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 943877448; verify_case(2, Arg1, order(Arg0)); }
	void test_case_3() { string Arr0[] = {"a", "b", "c", "d", "e", "f", "g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, order(Arg0)); }
	void test_case_4() { string Arr0[] = {"a", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, order(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RowsOrdering ___test;
	___test.run_test(-1);
}
// END CUT HERE
