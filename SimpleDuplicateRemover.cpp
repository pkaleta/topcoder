#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <list>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class SimpleDuplicateRemover {
    public:
        vector <int> process(vector <int> s) {
            int tmp[1005];
            memset(tmp, 0, sizeof(tmp));

            vector <int>::reverse_iterator i;
            vector <int> res;
            for (i = s.rbegin(); i != s.rend(); ++i) {
                if (!tmp[*i]) {
                    tmp[*i] = 1;
                    res.push_back(*i);
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }
};
