#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class CubeStickers {
    public:
        string isPossible(vector <string> sticker) {
            map<string, int> m;
            map<string, int>::iterator it;

            for (int i = 0; i < sticker.size(); ++i) {
                if (m.find(sticker[i]) == m.end()) {
                    m[sticker[i]] = 1;
                } else {
                    m[sticker[i]]++;
                }
            }

            vector<int> v;
            for (it = m.begin(); it != m.end(); ++it) {
                v.push_back(it->second);
            }

            sort(v.begin(), v.end());

            int cnt = 0;
            int i = v.size() - 1;
            while (i >= 0 && v[i] >= 2) {
                ++cnt;
                --i;
            }

            cout << v.size()-cnt << endl;
            cout << 6- 2*cnt << endl;
            if (cnt >= 3 || (v.size() - cnt >= 6 - 2*cnt)) {
                return "YES";
            }
            return "NO";
        }
};
