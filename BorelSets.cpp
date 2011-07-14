#include <string>
#include <vector>
#include <bitset>
#include <limits>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

class BorelSets {
    private:
        int create(string s) {
            int set = 0;

            if (s.size() > 0) {
                stringstream ss;
                ss << s;
                int x = 0;

                while (!ss.eof()) {
                    ss >> x;
                    set |= 1 << (x-1);
                }
            }
            return set;
        }

    public:
        int howMany(int size, vector <string> subsets) {
            map<int, bool> sets;
            map<int, bool> fresh;
            map<int, bool>::iterator it;
            for (int i = 0; i < subsets.size(); ++i) {
                sets[create(subsets[i])] = true;
            }

            do {
                for (it = fresh.begin(); it != fresh.end(); ++it) {
                    sets[it->first] = true;
                }
                cout << endl;
                fresh.clear();

                for (it = sets.begin(); it != sets.end(); ++it) {
                    int tmp = (1 << size) - 1;
                    int cmpl = ~(it->first) & tmp;

                    if (sets.find(cmpl) == sets.end()) {
                        fresh[cmpl] = true;
                    }

                    map<int, bool>::iterator jt;
                    for (jt = sets.begin(); jt != sets.end(); ++jt) {
                        if (it != jt) {
                            int un = it->first | jt->first;
                            if (sets.find(un) == sets.end()) {
                                fresh[un] = true;
                            }
                        }
                    }
                }
            } while (!fresh.empty());

            return sets.size();
        }
};
