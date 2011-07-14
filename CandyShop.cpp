#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

class CandyShop {
    public:
        int m[410][410];

        int dist(int x0, int y0, int x, int y) {
            return abs(x-x0) + abs(y-y0);
        }

        int countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R) {
            memset(m, 0, sizeof(m));

            for (int k = 0; k < X.size(); ++k) {
                for (int i = 0; i < 410; ++i) {
                    for (int j = 0; j < 410; ++j) {
                        if (dist(X[k]+205, Y[k]+205, j, i) <= R[k])
                            m[j][i]++;
                    }
                }
            }

            int res = 0;

            for (int i = 0; i < 410; ++i) {
                for (int j = 0; j < 410; ++j) {
                    if (m[j][i] == X.size()) res++;
                }
            }

            return res;
        }
};
