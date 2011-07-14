#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1000005;
const long long MOD = 1000000007;


class GuessTheNumberGame {
    public:
        int possibleClues(int n) {
            bool prime[MAX];
            for (int i = 0; i <= n; ++i) {
                prime[i] = true;
            }
            prime[0] = prime[1] = false;
            long long ret = 1;

            for (long long p = 2; p <= n; ++p) {
                if (prime[p]) {
                    long long count = 1;
                    for (long long i = p; i <= n; i *= p) {
                        ++count;
                    }
                    ret = (ret * count) % MOD;
                    for (long long i = p+p; i <= n; i += p) {
                        prime[i] = false;
                    }
                }
            }

            return ret;
        }
};
