#include <string>
#include <vector>

using namespace std;


class FiveHundredEleven {
    public:
        string theWinner(vector <int> cards) {
            int t[520];
            memset(t, 0, sizeof(t));


            for (int i = 0; i < cards.size(); ++i) {
                for (j = 0; j < 520; ++j) {
                    if (t[j] > 0) {
                        t[j|cards[i]] = min(t[j]+1, t[j|cards[i]]);
                    }
                }
            }

            if (t[511] & 1) {
                return "Fox Ciel";
            } else 
        }
};
