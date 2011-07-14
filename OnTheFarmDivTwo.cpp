// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
There are some chickens and some cows in Farmer John's yard.


John's daughter Susie counted that all the animals in the yard have a total of 3 heads. 
John's son Billy counted their legs and got a total of 8. 
Using their answers, Farmer John easily determined that there have to be exactly 2 chickens and 1 cow.


Write a method that will solve a general version of Farmer John's problem.
You are given two ints heads and legs. Compute the number of chickens and the number of cows. Return a vector <int> with two elements: first the number of chickens, then the number of cows. If there is no solution, return an empty vector <int> instead.


DEFINITION
Class:OnTheFarmDivTwo
Method:animals
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> animals(int heads, int legs)


NOTES
-If the solution exists, it is always unique.
-A chicken has 1 head and 2 legs. A cow has 1 head and 4 legs.


CONSTRAINTS
-heads will be between 0 and 1,000,000, inclusive.
-legs will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
3
8

Returns: {2, 1 }

Two chickens and a cow have a total of three heads and eight legs.

1)
10
40

Returns: {0, 10 }

Ten cows.

2)
10
42

Returns: { }

This test case has no solution because the number of legs is too large (or the number of heads is too small).

3)
1
3

Returns: { }

No set of animals can have one head and three legs.

4)
0
0

Returns: {0, 0 }

// END CUT HERE
#line 76 "OnTheFarmDivTwo.cpp"
#include <string>
#include <vector>
class OnTheFarmDivTwo {
	public:
	vector <int> animals(int heads, int legs) {
		
	}
};
