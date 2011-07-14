/* To, co chce wklejac do kodu zawsze; pamietajmy o 300-znakowym limicie
 * na liczbe niebialych znakow, ktore NIE obejmuja include'ow. */
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

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

$BEGINCUT$
/* To wszystko sie nie wklei do ostatecznego rozwiazania, ale moge
 * tego tu uzywac i w razie potrzeby przekleic cos stad do gory na koniec,
 * czyli tuz przed samym wyslaniem. */
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define INFTY 100000000
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)

ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

VS parse(string s)
{
  string a;
  VS wyn;
  REP(i,s.size())
    if (s[i]!=' ') a+=s[i];
    else if (!a.empty()) { wyn.PB(a); a=""; }
  if (!a.empty()) wyn.PB(a);
  return wyn;
}

int toi(char ch) { return int(ch)-int('0'); }

int chg(char ch) { return int(ch)-int('a'); }
$ENDCUT$

/* To jest obowiazkowa czesc; pozwalam co najwyzej pomodyfikowac wciecia :-) */
class $CLASSNAME$ 
{
  public:
  $RC$ $METHODNAME$($METHODPARMS$)
  {
    /* Tu bedzie start pisania */
  }
  $TESTCODE$
};


// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
  $CLASSNAME$ ___test;
  int x = argc == 1 ? 0 : atoi(argv[1]);
  ___test.run_test(x);
  if (x==100 || argc == 2)
    return 0;
  x++;
  char
    txt[30];
  sprintf(txt, "%d", x);
  execlp(argv[0], argv[0], txt, txt, NULL);
}
// END CUT HERE
