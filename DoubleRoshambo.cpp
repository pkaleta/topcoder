#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class DoubleRoshambo {
    public:
        int maxScore(vector <string> a, vector <string> b) {
            char w[256];
            memset(w, 0, sizeof(w));
            w['R'] = 'P';
            w['S'] = 'R';
            w['P'] = 'S';

            vector<string> aa;
            vector<string> bb;
            int ret = 0;

            int flag = true;
            while (flag) {
                flag = false;
                for (vector<string>::iterator i = b.begin(); i != b.end(); ++i) {
                    for (vector<string>::iterator j = a.begin(); j != a.end(); ++j) {
                        if ((*j)[0] == w[(*i)[0]] && (*j)[1] == w[(*i)[1]]) {
                            ret += 2;
                            flag = true;
                            a.erase(j);
                            b.erase(i);
                            break;
                        }
                    }
                    if (flag) break;
                }
            }

            flag = true;
            while (flag) {
                flag = false;
                for (vector<string>::iterator i = b.begin(); i != b.end(); ++i) {
                    for (vector<string>::iterator j = a.begin(); j != a.end(); ++j) {
                        if ((*j)[0] == (*i)[0] && (*j)[1] == w[(*i)[1]]) {
                            ret += 1;
                            flag = true;
                            a.erase(j);
                            b.erase(i);
                            break;
                        }
                    }
                    if (flag) break;
                }
            }

            return ret;
        }
};
