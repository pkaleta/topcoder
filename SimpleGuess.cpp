#include <string>
#include <vector>

using namespace std;

class SimpleGuess {
    public:
        int getMaximum(vector <int> hints) {
            int result = 0;
            int x, y;
            for (int i = 0; i < hints.size(); ++i) {
                for (int j = 0; j < hints.size(); ++j) {
                    int a = hints[i];
                    int b = hints[j];
                    if (i != j && (a+b) % 2 == 0 && (a-b) % 2 == 0) {
                        x = (a+b)/2;
                        y = (a-b)/2;
                        if (x * y > result) {
                            result = x * y;
                        }
                    }
                }
            }
            return result;
        }
};
