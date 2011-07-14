#include <string>
#include <vector>
#include <string>

using namespace std;

class PalindromeGame {
    public:
        vector<string> f;
        vector<int> b;

        bool used[100];

        bool ispalin(string a, string b) {
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != b[b.size()-i-1])
                    return false;
            }
            return true;
        }

        int calc() {
            int maxi = -1;
            int maxj = -1;
            int m = -1;

            for (int i = 0; i < f.size(); ++i) {
                if (!used[i]) {
                    for (int j = 0; j < f.size(); ++j) {
                        if (i != j && !used[j]) {
                            if (ispalin(f[i], f[j]) && b[i] + b[j] > m) {
                                maxi = i;
                                maxj = j;
                                m = b[i]+b[j];
                            }
                        }
                    }
                }
            }

            if (maxi != -1) {
                used[maxi] = true;
                used[maxj] = true;
                return m + calc();
            } else {
                int tmp = 0;
                for (int i = 0; i < f.size(); ++i) {
                    if (!used[i] && ispalin(f[i], f[i]) && b[i] > tmp) {
                        tmp = b[i];
                    }
                }
                return tmp;
            }
        }

        int getMaximum(vector <string> f, vector <int> b) {
            this->f = f;
            this->b = b;
            memset(used, 0, sizeof(used));
            return calc();
        }
};
