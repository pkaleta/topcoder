// BEGIN CUT HERE
// PROBLEM STATEMENT
// After the shortage of IPv444 (Internet Protocol version 444) addresses had occurred, Fox Ciel decided to sell her IPv444 addresses to the traders.
An IP address in IPv444 is the concatenation of four integers between 0 and 999, inclusive, in decimal notation with no extra leading zeroes, separated by periods ('.'). For example, the following two strings are valid IPv444 addresses.

  66.37.210.86
  123.456.789.0

In addition, in IPv444, there is a way to represent some IP addresses by using a wildcard character '*'. Each '*' character replaces one of the four integers in the address, and represents all integers between 0 and 999, inclusive.
For example, "23.4.*.8" represents 1000 IP addresses: "23.4.0.8", "23.4.1.8", ..., "23.4.999.8", and "*.4.*.8" represents 1000000 IP addresses.

Ciel received requests from some traders to sell her addresses. i-th trader requests IP addresses represented by request[i], and the trader promised to pay price[i] dollars for each requested address.
Each IP address can be sold to at most one trader, and each trader does not require all the IP addresses he requested. Assume that she owns all the IP addresses that have been requested by the traders.
Return the maximum amount of money Ciel can gain.


DEFINITION
Class:IPv444
Method:getMaximumMoney
Parameters:vector <string>, vector <int>
Returns:long long
Method signature:long long getMaximumMoney(vector <string> request, vector <int> price)


CONSTRAINTS
-request will contain between 1 and 50 elements, inclusive.
-request and price will contain the same number of elements.
-Each element of request will be formatted as described in the statement.
-price will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{"66.37.210.86"}
{47}

Returns: 47

An optimal way is to sell IP address "66.37.210.86" to the 0-th trader. Then Ciel would gain 47 dollars.


1)
{"0.0.0.*", "0.0.0.3", "0.0.0.5"}
{1, 3, 9}

Returns: 1010

Ciel is going to sell 1,000 addresses "0.0.0.0", ..., "0.0.0.999" to the traders.
An optimal way is to sell "0.0.0.3" to trader 1, "0.0.0.5" to trader 2, and the other 998 addresses to trader 0. Ciel would gain 3*1+9*1+1*998=1010 dollars.


2)
{"*.*.*.*", "123.456.789.0", "434.434.434.434", "999.*.999.*"}
{1, 5, 3, 6}

Returns: 1000005000006

It is possible for Ciel to gain a tremendous amount of money.


3)
{"*.*.999.999", "888.888.999.*", "888.888.*.999", "777.777.777.777", "777.*.*.777"}
{19, 33, 42, 777, 7}

Returns: 26075718



4)
{"127.0.0.1", "*.0.0.*", "*.*.255.255", "192.68.*.*"}
{999999, 629851, 294016, 438090}

Returns: 1361957076132



// END CUT HERE
#line 80 "IPv444.cpp"
#include <string>
#include <vector>
class IPv444 {
	public:
	long long getMaximumMoney(vector <string> request, vector <int> price) {
		
	}
};
