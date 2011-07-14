#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
using namespace std;

typedef vector<int> VI;

class Jewelry {
    public:
        static const int max_pieces = 35;
        static const int max_value = 1005;

        void calc(VI::iterator a, VI::iterator b, long long t[], long long s) {
            VI::iterator i;
            long long tmp[max_value*max_pieces];

            memset(t, 0, sizeof(long long)*max_value*max_pieces);

//            cout << endl;
//            cout << "uzywam: ";
            for (i = a; i != b; i++) {
                memset(tmp, 0, sizeof(long long)*max_value*max_pieces);
//                cout << *i << " ";
                for (int j = 1; j <= s; ++j) {
                    if (t[j]) {
                        tmp[j+(*i)] += t[j];
                    }
                }
                tmp[*i]++;
                for (int j = 1; j <= s; ++j) {
                    t[j] += tmp[j];
                }
            }
//            cout << endl;
        }

        long long howMany(VI vs) {
            long long ta[max_value*max_pieces];
            long long tb[max_value*max_pieces];
            long long tmp[max_value*max_pieces];
            long long result = 0;
            long long sa = vs[0];
            long long sb = 0;
            VI::iterator ii;

            memset(ta, 0, sizeof(long long)*max_value*max_pieces);

            for (int i = 1; i < vs.size(); ++i)
                sb += vs[i];

            sort(vs.begin(), vs.end());

            for (int i = 1; i < vs.size(); ++i) {
//                cout << "a (" << sa << ") : ";
//                for (int j = 0; j < i; ++j) {
//                    cout << vs[j] << " ";
//                }
//                cout << endl;
//                calc(vs.begin(), vs.begin()+i, ta, min(sa, sb));


                for (int j = 1; j <= sa; ++j) {
                    if (ta[j]) {
                        tmp[j+vs[i-1]] += ta[j];
                    }
                }
                tmp[vs[i-1]]++;
//                cout << endl;

                cout << "tmp: ";
                for (int j = 1; j < 20; ++j) {
                    cout << j << " ";
                }
                cout << endl;
                cout << "tmp: ";
                for (int j = 1; j < 20; ++j) {
                    cout << tmp[j] << " ";
                }
                cout << endl;

                calc(vs.begin()+i, vs.end(), tb, min(sa, sb));
                cout << "b (" << sb << ") : ";
                for (int j = i; j < vs.size(); ++j) {
                    cout << vs[j] << " ";
                }
                cout << endl;
                cout << "b: ";
                for (int j = 1; j < 20; ++j) {
                    cout << j << " ";
                }
                cout << endl;
                cout << "b: ";
                for (int j = 1; j < 20; ++j) {
                    cout << tb[j] << " ";
                }
                cout << endl;

                for (int j = 0; j < max_pieces*max_value; ++j) {
                    if (tmp[j] && tb[j]) {
                        result += tmp[j]*tb[j];
                    }
                }

                for (int j = 1; j <= sa; ++j) {
                    ta[j] += tmp[j];
                }
                memset(tmp, 0, sizeof(long long)*max_value*max_pieces);

                sa += vs[i];
                sb -= vs[i];
            }

            return result;
        }
};
