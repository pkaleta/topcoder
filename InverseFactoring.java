// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A positive integer a is a proper factor of n if and only if n is a multiple of a and a does not equal 1 or n.  You are given a int[] factors containing all the proper factors of some integer n.  Return n.

DEFINITION
Class:InverseFactoring
Method:getTheNumber
Parameters:int[]
Returns:int
Method signature:int getTheNumber(int[] factors)


CONSTRAINTS
-factors will contain between 1 and 50 elements, inclusive.
-factors will be a valid set of proper factors of some number n, where n is between 2 and 1,000,000, inclusive.
-All elements in factors will be distinct.


EXAMPLES

0)
{2}

Returns: 4

The factors of 4 are 1, 2 and 4. Among them, only 2 is a proper factor.

1)
{4,2}

Returns: 8

The factors of 8 are 1, 2, 4, and 8. Among them, 2 and 4 are proper factors.

2)
{3,4,2,12,6,8}

Returns: 24

The proper factors of 24 are 2, 3, 4, 6, 8 and 12.

3)
{14,26456,2,28,13228,3307,7,23149,8,6614,46298,56,4,92596}

Returns: 185192

*/
// END CUT HERE
import java.util.*;
public class InverseFactoring
{

	public int getTheNumber(int[] f) 
	{
        Arrays.sort(f);
        return f[0] * f[f.length - 1];
	}

	/*
	public static void main(String[] args) 
	{|
		InverseFactoring temp = new InverseFactoring();
		System.out.println(temp.getTheNumber(int[] factors));
	}
	*/
}
