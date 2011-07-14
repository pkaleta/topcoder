#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Zoo {
    public:
        long long theCount(vector<int> ans) {
            int cnt[50];
            memset(cnt, 0, sizeof(cnt));

            for (int i = 0; i < ans.size(); ++i) {
                cnt[ans[i]]++;
            }

            if (cnt[0] > 2) {
                return 0;
            }
            for (int i = 1; i < 50; ++i) {
                if (cnt[i] > 2 || (cnt[i] > cnt[i-1])) {
                    return 0;
                }
            }

            int twos = 0;
            int ones = 0;
            for (int i = 0; i <= 50; ++i) {
                if (cnt[i] == 2) {
                    twos++;
                } else if (cnt[i] == 1) {
                    ones++;
                }
            }

            cout << twos << " " << ones << endl;
            int result = 1 << twos;
            if (ones > 0) {
                result *= 2;
            }

            return result;

        }
};
