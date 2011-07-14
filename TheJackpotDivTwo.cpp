#include <string>
#include <vector>

using namespace std;

class TheJackpotDivTwo {
    public:
        vector <int> find(vector <int> money, int jackpot) {
            int m;
            while (jackpot--) {
                m = 0;
                for (int i = 1; i < money.size(); ++i) {
                    if (money[i] < money[m]) {
                        m = i;
                    }
                }
                ++money[m];
            }
            sort(money.begin(), money.end());
            return money;
        }
};
