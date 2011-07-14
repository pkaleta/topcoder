#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TheLuckyBasesDivTwo {
    public:
        map<pair<long long, long long>, bool> m;

        long long f(long long n, long long b) {
            if (n == b) return 0;
            if (n < 0) return 0;
            if ((b > 7 && n == 7) || (b > 4 && n == 4)) {
                return 1;
            }

            int ret = 0;
            if (b > 4 && ((n-4) % b == 0)) {
                ret += f((n-4)/b, b);
            }
            if (b > 7 && ((n-7) % b == 0)) {
                ret += f((n-7)/b, b);
            }

            return ret;
        }

        long long find(long long N) {
            if (N == 4 || N == 7) {
                return -1;
            }

            long long ret = 0;

            long long n = N-4;
            for (long long d = 4; d*d < n; ++d) {
                if (n % d == 0) {
                    if (n/d > 4)
                        ret += f(d, n/d);
                    if (d > 4)
                        ret += f(n/d, d);
                }
            }

            n = N-7;
            for (long long d = 4; d*d < n; ++d) {
                if (n % d == 0) {
                    if (n/d > 7)
                        ret += f(d, n/d);
                    if (d > 7)
                        ret += f(n/d, d);
                }
            }
            return ret;
        }
};

