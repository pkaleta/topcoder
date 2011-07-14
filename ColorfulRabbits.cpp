#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class ColorfulRabbits {
    public:
        int getMinimum(vector <int> rs) {
            sort(rs.begin(), rs.end());
            int i = 0;
            int result = 0;

            while (i < rs.size()) {
                int current = rs[i];
                ++i;
                int count = 1;
                bool flag = false;
                while (i < rs.size() && rs[i] == rs[i-1]) {
                    flag = true;
                    ++i;
                    ++count;
                }
                int tmp = count / (current+1);
                if (count % (current+1) != 0) {
                    ++tmp;
                }
                result += tmp*(current+1);
            }
            return result;
        }
};
