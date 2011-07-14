#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
#include <exception>
#include <cmath>

using namespace std;

class CubeRoll {
    public:

        bool vis[100005];

        bool sqr(long long x) {
            long long sqrtx = (long long)sqrt(x + 0.5);
            return sqrtx*sqrtx == x;
        }

        long long getMinimumSteps(long long initPos, long long goalPos, vector <int> hole) {
            queue<pair<int, int> > q;

            long long tmp;
            if (initPos > goalPos) {
                tmp = initPos;
                initPos = goalPos;
                goalPos = tmp;
            }
            memset(vis, 0, sizeof(vis));
            vis[initPos] = true;
            q.push(make_pair(initPos, 0));

            long long inf = 1<<30;
            int left = -inf;
            int right = inf;

            for (long long i = 0; i < hole.size(); ++i) {
                if (initPos < hole[i] && hole[i] < goalPos) {
                    return -1;
                } else if (goalPos < hole[i]) {
                    right = min(right, hole[i]);
                } else if (initPos > hole[i]) {
                    left = max(left, hole[i]);
                }
            }

            if (left != -inf && right != inf) {
                while (!q.empty()) {
                    pair<int, int> x = q.front();
                    q.pop();

                    long long pos = x.first;
                    long long dist = x.second;
                    cout << "*************** " << pos << endl;

                    if (pos == goalPos)
                        return dist;

                    long long npos;
                    for (long long i = 1; (npos = pos + i*i) < right; ++i) {
                        if (!vis[npos]) {
                            vis[npos] = true;
                            q.push(make_pair(npos, dist+1));
                        }
                    }

                    for (long long i = 1; (npos = pos - i*i) > left; ++i) {
                        if (!vis[npos]) {
                            vis[npos] = true;
                            q.push(make_pair(npos, dist+1));
                        }
                    }
                }
                return -1;
            }

            long long x = goalPos - initPos;

            if (sqr(x)) return 1;
            for (long long d = 1; d < 60000; ++d) {
                if (sqr(x-d*d) || sqr(d*d-x))
                    return 2;
            }

            return 3;
        }
};
