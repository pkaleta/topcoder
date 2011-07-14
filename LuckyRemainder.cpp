#include <string>
#include <vector>

using namespace std;

class LuckyRemainder {
    public:
        int getLuckyRemainder(string X) {
            int p = 1;
            int s = X[0]-'0';
            for (int i = 1; i < X.size(); ++i) {
                p = (p*2) % 9;
                s = (s+X[i]-'0') % 9;
            }
            return (p*s)%9;
        }
};
