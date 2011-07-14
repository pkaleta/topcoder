#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <list>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;

class MarbleNecklace {
    public:
        string normalize(string necklace) {
            string res = necklace;

            for (int i = 0; i < necklace.size(); ++i) {
                string tmp = necklace.substr(i, necklace.size() - i + 1) +
                    necklace.substr(0, i);
                if (tmp.compare(res) < 0) {
                    res = tmp;
                }
            }
            reverse(necklace.begin(), necklace.end());
            for (int i = 0; i < necklace.size(); ++i) {
                string tmp = necklace.substr(i, necklace.size() - i + 1) +
                    necklace.substr(0, i);
                if (tmp.compare(res) < 0) {
                    res = tmp;
                }
            }
            return res;
        }
};

int main() {
    MarbleNecklace* necklace = new MarbleNecklace();
    cout << necklace->normalize("SONBZELGFEQMSULZCNPJODOWPEWLHJFOEW") << endl;
    return 0;
}
