// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You wish to group a list of numbers into pairs such that the sum of each pair is prime.
For example, given the numbers { 1, 4, 7, 10, 11, 12 }, you could group them as follows:



 1 +  4 =  5
 7 + 10 = 17
11 + 12 = 23


or:


 1 + 10 = 11
 4 +  7 = 11
11 + 12 = 23



Given a int[] numbers, return a int[] of all the elements
in numbers that could be paired with numbers[0] successfully as part of a complete pairing,
sorted in ascending order.
Note that in the example above, even though 1 + 12 is prime, there would be no way to
pair the remaining 4 numbers.
So the answer for the example above would be { 4, 10 }.



DEFINITION
Class:PrimePairs
Method:matches
Parameters:int[]
Returns:int[]
Method signature:int[] matches(int[] numbers)


NOTES
-A prime number is a number divisible only by 1 and itself.


CONSTRAINTS
-numbers will contain an even number of elements, between 2 and 50, inclusive.
-Each element of numbers will be between 1 and 1000, inclusive.
-Each element of numbers will be distinct.


EXAMPLES

0)
{ 1, 4, 7, 10, 11, 12 }

Returns: {4, 10 }

This is the example from the problem statement.

1)
{ 11, 1, 4, 7, 10, 12 }

Returns: {12 }

The same numbers, but in a different order.  In both of the 2 possible complete pairings, the 11 is paired with the 12.

2)
{ 8, 9, 1, 14 }

Returns: { }

No complete pairings are possible because none of the numbers can be paired with 1.

3)
{ 34, 39, 32, 4, 9, 35, 14, 17 }

Returns: {9, 39 }



4)
{ 941, 902, 873, 841, 948, 851, 945, 854, 815, 898,
  806, 826, 976, 878, 861, 919, 926, 901, 875, 864 }


Returns: {806, 926 }



*/
// END CUT HERE
import java.util.*;
public class PrimePairs
{
	public int[] matches(int[] numbers) 
	{
		
	}

	/*
	public static void main(String[] args) 
	{
		PrimePairs temp = new PrimePairs();
		System.out.println(temp.matches(int[] numbers));
	}
	*/
}
