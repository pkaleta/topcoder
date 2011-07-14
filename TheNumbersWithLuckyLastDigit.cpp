#include <string>
#include <vector>

class TheNumbersWithLuckyLastDigit {
    public:

        int find(int n) {
            int t[10] = {5, 2, 3, 5, 1, 3, 4, 1, 2, 4};
            int v[10] = {20, 11, 12, 23, 4, 15, 16, 7, 8, 19};
            int last = n % 10;

            if (n % 10 == 7)
                return 1;
            if (n < v[last])
                return -1;
            return t[last];
        }
};
