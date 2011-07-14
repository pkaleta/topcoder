// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Consider the set of numbers formed by taking every number between low and high, inclusive, and sorting the digits of each number in non-increasing order (the numbers are initially written without any extra leading zeros). Return the number of distinct numbers in this new set.

DEFINITION
Class:DistinctDigits
Method:count
Parameters:int, int
Returns:int
Method signature:int count(int low, int high)


CONSTRAINTS
-high will be between 1 and 100,000,000 (10^8), inclusive.
-low will be between 1 and high, inclusive.


EXAMPLES

0)
1
20

Returns: 20

All of the integers between 1 and 20 have distincts sets of digits.

1)
1
30

Returns: 29

"21" has the same digits as "12" when sorted. All the rest are still distinct.

2)
151
309

Returns: 98



3)
1
15000

Returns: 1641



4)
153697
154689

Returns: 318



5)
1000
10000000

Returns: 19159



*/
// END CUT HERE
import java.util.*;
public class DistinctDigits
{
	public int count(int low, int high) 
	{
		
	}

	/*
	public static void main(String[] args) 
	{
		DistinctDigits temp = new DistinctDigits();
		System.out.println(temp.count(int low, int high));
	}
	*/
}
