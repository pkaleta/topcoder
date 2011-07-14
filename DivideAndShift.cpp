#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class DivideAndShift {
    public:
        vector<int> primes;

        int getLeast(int N, int M) {
            if (M == 1) return 0;

            map<pair<int, int>, int>::iterator it;

            int res = min (M-1, N-M+1);

            for (int i = 2; i <= N; ++i) {
                if (N % i == 0 && isPrime(i)) {
                    int nelem = N / i;

                    int newM;
                    if (M % nelem == 0)
                        newM = nelem;
                    else
                        newM = M % nelem;

                    int tmp = 1 + getLeast(nelem, newM);
                    res = min(res, tmp);
                }
            }

            return res;
        }

        int isPrime(int n) {
            for (int i = 2; i*i <= n; ++i) {
                if (n % i == 0)
                    return false;
            }
            return true;
        }
};
