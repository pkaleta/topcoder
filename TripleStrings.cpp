#include <string>
#include <vector>
#include <iostream>


using namespace std;


bool check(string a, string b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

class TripleStrings {
    public:
        int getMinimumOperations(string init, string goal) {
            int maxLen = 0;
            for (int i = 1; i <= goal.size(); ++i) {
                if (check(goal.substr(0, i), init.substr(init.size()-i, i))) {
                    maxLen = i;
                }
            }

            return (init.size()-maxLen)*2;
        }
};
