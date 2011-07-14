#include <string>
#include <vector>

using namespace std;

class ColoredStrokes {
    public:
        int getLeast(vector <string> p) {
            int result = 0;
            for (int i = 0; i < p.size(); ++i) {
                for (int j = 0; j < p[i].size(); ++j) {
                    if (p[i][j] == 'R') {
                        ++result;

                        int jj = j;
                        while (jj < p[0].size() && (p[i][jj] == 'R' || p[i][jj] == 'G')) {
                            if (p[i][jj] == 'R') {
                                p[i][jj] = 'X';
                            }
                            ++jj;
                        }
                    }
                }
            }

            for (int i = 0; i < p.size(); ++i) {
                for (int j = 0; j < p[i].size(); ++j) {
                    if (p[i][j] == 'B') {
                        ++result;

                        int ii = i;
                        while (ii < p.size() && (p[ii][j] == 'B' || p[ii][j] == 'G')) {
                            p[ii][j] = 'X';
                            ++ii;
                        }
                    }
                }
            }

            for (int i = 0; i < p.size(); ++i) {
                for (int j = 0; j < p[i].size(); ++j) {
                    if (p[i][j] == 'G') {
                        ++result;
                    }
                }
            }

            return result;
        }
};
