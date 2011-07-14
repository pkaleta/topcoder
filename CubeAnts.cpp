#include <string>
#include <vector>

using namespace std;

class CubeAnts {
    public:
        int getMinimumSteps(vector <int> pos) {
            int dist[8] = {0, 1, 2, 1, 1, 2, 3, 2};

            int res = -1;
            for (int i = 0; i < pos.size(); ++i) {
                res = max(res, dist[pos[i]]);
            }
            return res;
        }
};
