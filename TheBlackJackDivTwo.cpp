#include <string>
#include <vector>

using namespace std;

class TheBlackJackDivTwo {
    public:
        int score(vector <string> cards) {
            int res = 0;
            for (int i = 0; i < cards.size(); ++i) {
                if (cards[i][0] >= '0' && cards[i][0] <= '9') {
                    res += cards[i][0] - '0';
                } else if (cards[i][0] == 'T') {
                    res += 10;
                } else if (cards[i][0] == 'A') {
                    res += 11;
                } else {
                    res += 10;
                }
            }
            return res;
        }
};
