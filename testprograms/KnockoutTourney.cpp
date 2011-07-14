#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class KnockoutTourney {
public:
  int meetRival(int, int, int);
};
 
int KnockoutTourney::meetRival(int N, int you, int rival) {
  int l[100005];
  int m[100005];
  for (int i = 1; i <= N; ++i) {
    l[i] = m[i] = i;
  }
  int n = N;
  int round = 1;
  while (n) {
  	cout << n << endl;
    for (int i = 2; i <= n; i += 2) {
      //cout << l[i-1] << " , " << l[i] << endl;
      if ((l[i] == you || l[i-1] == you) && (l[i] == rival || l[i-1] == rival))
        return round;
      if (l[i] == you || l[i-1] == you) {
        m[i/2] = you;
      }
      else if (l[i] == rival || l[i-1] == rival) {
        m[i/2] = rival;
      }
      else m[i/2] = l[i];
    }
    n /= 2;
    for (int i = 1; i <= n; ++i) {
      l[i] = m[i];
    }
    ++round;
  }
  return 0;
}
