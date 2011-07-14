#include <string>
#include <vector>

using namespace std;

class BlackWhiteMagic {
    public:
        int count(string cs) {
            int b = 0;
            int w = 0;
            for (int i = 0; i < cs.size(); ++i)
            {
                if (cs[i] == 'W')
                    w++;
                else
                    b++;
            }
            int result = 0;
            for (int i = 0; i < w; ++i) {
                if (cs[i] == 'B')
                    result++;
            }
            return result;
        }
};
