#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int t[16][16][2];

class TheCardLineDivTwo {
    public:
        bool match(string a, string b) {
            return a[0] == b[0] ||(a[1] == b[1] ||
                    (a[1] == 'D' && b[1] == 'H') ||
                    (a[1] == 'H' && b[1] == 'D') ||
                    (a[1] == 'S' && b[1] == 'C') ||
                    (a[1] == 'C' && b[1] == 'S')
                );
        }

        int count(vector <string> cards) {
            memset(t, 0, sizeof(t));
            for (int i = 0; i < cards.size(); ++i) {
                for (int j = 0; j < cards.size(); ++j) {
                    t[i][j][0] = t[i][j][1] = 1;
                }
            }

            for (int i = 0; i < cards.size(); ++i) {
                for (int p = 0; p < i; ++p) {
                    for (int k = 0; k < i; ++k) {
                        if (p != k) {
                            if (match(cards[i], cards[p]) && match(cards[i], cards[k])) {
                                printf("match: %s - %s - %s\n", cards[p].c_str(), cards[i].c_str(), cards[k].c_str());
                                for (int x = 0; x < 16; ++x) {
                                    for (int y = 0; y < 16; ++y) {
                                        if (x != y) {
                                            t[p][x + y][1] += t[k][x + y][0];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                for (int j = 0; j < i; ++j) {
                    if (match(cards[i], cards[j])) {
                        printf("match: %s - %s\n", cards[i].c_str(), cards[j].c_str());
                        for (int x = 0; x < 16; ++x) {
                            t[i][x + 1][0] += t[j][x][0];
                            t[i][x + 1][1] += t[j][x][1];
                            t[j][x + 1][0] += t[i][x][0];
                            t[j][x + 1][1] += t[i][x][1];
                        }
                    }
                }
            }
            for (int j = 0; j < cards.size(); ++j) {
                printf("%s: \n", cards[j].c_str());
                for (int i = 0; i < cards.size(); ++i) {
                    printf("dlug: %d, zaczyna: %d, konczy: %d\n", i, t[j][i][0], t[j][i][1]);
                }
            }
        }
};

int main() {
    TheCardLineDivTwo* c = new TheCardLineDivTwo();
    vector<string> cards;
    cards.push_back("KH");
    cards.push_back("QD");
    cards.push_back("KC");
    cout << c->count(cards) << endl;

    return 0;
}
