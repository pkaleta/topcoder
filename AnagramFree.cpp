#include <string>
#include <cstring>
#include <vector>


using namespace std;

class AnagramFree {
    public:
        bool isAnagram(string& a, string& b) {
            int ca[256];
            memset(ca, 0, sizeof(ca));
            int cb[256];
            memset(cb, 0, sizeof(cb));

            if (a.size() != b.size())
                return false;
            for (int i = 0; i < a.size(); ++i) {
                ca[(int)a[i]]++;
                cb[(int)b[i]]++;
            }
            for (int i = 0; i < 256; ++i) {
                if (ca[i] != cb[i])
                    return false;
            }
            return true;
        }

        int getMaximumSubset(vector <string> S) {
            bool t[55];
            memset(t, 0, sizeof(t));
            for (int i = 0; i < S.size(); ++i) {
                for (int j = i+1; j < S.size(); ++j) {
                    if (isAnagram(S[i], S[j])) {
                        t[j] = true;
                    }
                }
            }
            int result = 0;
            for (int i = 0; i < S.size(); ++i) {
                if (t[i] == false) {
                    ++result;
                }
            }
            return result;
        }
};
