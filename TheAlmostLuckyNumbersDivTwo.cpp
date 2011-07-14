#include <string>
#include <vector>

using namespace std;

class TheAlmostLuckyNumbersDivTwo {
    public:
        bool check(int n) {
            int cnt = 0;
            while (n) {
                int d = n%10;
                n /= 10;
                if (d != 4 && d != 7) {
                    cnt++;
                }
            }
            if (cnt <= 1) {
                return true;
            } else {
                return false;
            }
        }
        int find(int a, int b) {
            int ret = 0;
            for (int i = a; i <= b; ++i) {
                ret += check(i);
            }
            return ret;
        }
};
