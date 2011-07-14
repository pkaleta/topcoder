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

class TheLuckyString {
public:
	int count(string);
	bool isLucky(string);
};

bool TheLuckyString::isLucky(string s)
{
	for (int i = 1; i < s.size(); ++i)
		if (s[i] == s[i-1])
			return false;
	return true;
}

int TheLuckyString::count(string s) {
	int cnt = 0;
    sort(s.begin(), s.end());
	do
		if (isLucky(s))
			cnt++;
	while (next_permutation(s.begin(), s.end()));
	return cnt;
}


//Powered by [KawigiEdit] 2.0!
