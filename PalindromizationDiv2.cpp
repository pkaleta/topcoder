#include <string>
#include <vector>
#include <sstream>

using namespace std;

class PalindromizationDiv2 {
    public:
        bool check(int x) {
            stringstream out;
            out << x;
            string s = out.str();

            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != s[s.size()-1-i]) {
                    return false;
                }
            }
            return true;
        }

        int getMinimumCost(int x) {
            int ret = 0;
            while (!check(x+ret) && (x-ret >= 0 && !check(x-ret))) {
                ++ret;
            }
            return ret;
        }
};
