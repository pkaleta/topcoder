#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 55;

class KindAndCruel {
    public:
        int crossTheField(string field, int K, int C) {
            int t[MAX];
            int next[MAX];
            memset(t, 0, sizeof(t));

            for (int i = 0; i < field.size()-1; ++i) {
                int ks = 0;
                int j = i+1;
                while (field[j] == 'K') {
                    ++j;
                    ++ks;
                }
                if (ks >= K)
                    return -1;

                next[i] = ks+1;
            }

            for (int i = 0; i < field.size(); ++i)
                cout << next[i];
            cout << endl;

            string f = "";
            int dist[MAX];
            memset(dist, 0, sizeof(dist));
            int i = 0;
            int j = 0;
            while (i < field.size()) {
                f = f + field[i];
                dist[j++] = next[i];
                i += next[i];
            }

            cout << f << endl;
            for (int i = 0; i < f.size(); ++i)
                cout << dist[i] << " ";
            cout << endl;


            int res = 1;
            int cur = next[0];
            for (int i = 1; i < f.size(); ++i) {
                
            }

            return 0;

        }
};
