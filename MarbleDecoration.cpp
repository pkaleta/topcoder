#include <string>
#include <vector>

using namespace std;

class MarbleDecoration {
    public:
        int maxLength(int R, int G, int B) {
            int t[3] = {R, G, B};
            sort(t, t+3);
            if (t[2] > t[1]) {
                return t[1]+t[1]+1;
            } else {
                return t[1]+t[1];
            }
        }
};
