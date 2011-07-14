#include <string>
#include <vector>

class TheCardShufflingDivTwo {
    public:
        int shuffle(int n, int m) {
            int cur = 0;
            for (int i = 0; i < m; ++i) {
                if (cur >= n / 2) {
                    cur = (cur - (n / 2)) * 2;
                } else {
                    cur = cur * 2 + 1;
                }
            }
            return cur + 1;
        }
};
