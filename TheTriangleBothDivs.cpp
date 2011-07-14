#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
//#include<cstdlib>
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
#include<stdlib.h>
using namespace std;


void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


class TheTriangleBothDivs {
    public:
        string getmins(string time) {
            string m = "";

            m += (time[3] == '?' ? '0' : time[3]);
            m += (time[4] == '?' ? '0' : time[4]);
            return m;
        }

        string gettime(string time) {
            string t = "";

            t += (time[0] == '?' ? '0' : time[0]);
            t += (time[1] == '?' ? '0' : time[1]);

            return t + ":" + getmins(time);
        }

        string convert(int gmt, int h) {
            h -= gmt;
            char tmp[3];
            itoa(h, tmp);
            return string(tmp);
        }

        bool match(int h, int gmt, string hour) {
            return ((hour[0] == '?' || hour[0] - '0' == (h - gmt) / 10) && \
                    (hour[1] == '?' || hour[1] - '0' == (h - gmt) % 10));
        }

        string fix(string time) {
            int gmt = -10;
            if (time[10] != '?')
                gmt = (time[10] - '0') * (44 - (time[9]));

            if (gmt != -10) {
                for (int h = 0; h < 24; ++h) {
                    if (match(h, gmt, time.substr(0, 2))) {
                        return convert(gmt, h) + ":" + getmins(time);
                    }
                }
            }
            else {
                return string("00:") + getmins(time);
            }
        }
};
