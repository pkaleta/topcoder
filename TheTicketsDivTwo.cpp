#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TheTicketsDivTwo {
    public:
        double find(int n, int m, int k) {
            if (k == 0)
            {
                if (m == 1)
                    return 1.0f;
                else
                    return 0.0f;
            }

            if (n == 1) {
                return 1.0f;//(1 + 3 * find(n, m, k-1)) / 6.0f;
            }

            if (m == 1) {
                return (1 + 3 * find(n, n, k-1)) / 6.0f;
            } else {
                return (2 * find(n-1, m-1, k-1) + 3 * find(n, m-1, k-1)) / 6.0f;
            }
        }
};
