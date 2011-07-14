// BEGIN CUT HERE
// PROBLEM STATEMENT
// A palindrome is a string that is the same whether it is read from left to right or from right to left.

Consider a string of length N which contains only uppercase letters. Write down all of its contiguous substrings of length M (a separate substring must be written down for each starting position, even if some of these substrings are the same strings). If at least K of the substrings you have written down are palindromes, we call the string palindromful.

Return the number of different palindromful strings of length N.

DEFINITION
Class:PalindromfulString
Method:count
Parameters:int, int, int
Returns:long long
Method signature:long long count(int N, int M, int K)


CONSTRAINTS
-N will be between 2 and 11, inclusive.
-M will be between 2 and N, inclusive.
-K will be between 0 and 11, inclusive. 


EXAMPLES

0)
2
2
1

Returns: 26

For a string of length 2, the only substring of length 2 is the string itself. Therefore, in this case we need to count palindromes of length 2, which are "AA", "BB", ..., "ZZ".

1)
2
2
0

Returns: 676

This time there can be no palindrome among the substrings, so any string of length 2 will do.

2)
3
2
1

Returns: 1326

Either the first two or the last two characters of the string should be equal, with no restrictions on the remaining one. This gives us 2*26*26=1352 variants, of which 26 are strings consisting entirely of the same character and therefore duplicated.

3)
4
4
1

Returns: 676

We're looking for palindromes of length 4.

4)
7
3
3

Returns: 4310176



// END CUT HERE
#line 72 "PalindromfulString.cpp"
#include <string>
#include <vector>
class PalindromfulString {
	public:
	long long count(int N, int M, int K) {
		
	}
};
