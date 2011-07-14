#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class GameOfLifeDivTwo {
    public:
        string get3(string& s, int i) {
            stringstream ss;
            int n = s.size();

            if (i == 0) {
                ss << s[0] << s[n-1] << s[1];
            } else if (i == n-1) {
                ss << s[n-1] << s[0] << s[n-2];
            } else {
                ss << s[i-1] << s[i] << s[i+1];
            }
            return ss.str();
        }

        int count(string& s) {
            int ret = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '1') ret++;
            }
            return ret;
        }

        string theSimulation(string s, int T) {
            while (T--) {
                string t = "";
                for (int i = 0; i < s.size(); ++i) {
                    string x = get3(s, i);
                    int cnt = count(x);
                    if (cnt >= 2) {
                        t += "1";
                    }
                    else if (cnt <= 1) {
                        t += "0";
                    }
                }
                s = t;
            }
            return s;
        }
};
