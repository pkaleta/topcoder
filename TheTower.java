// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
N checkers are placed on an infinitely large board.  The i-th checker is in the cell at row x[i], column y[i].  There can be more than one checker in the same cell.  A move consists of taking one checker and moving it one cell up, down, left or right.



Return a int[] containing exactly N elements, where the i-th element (0-based) is the minimum number of moves necessary to end up with at least i+1 checkers in the same cell.



DEFINITION
Class:TheTower
Method:count
Parameters:int[], int[]
Returns:int[]
Method signature:int[] count(int[] x, int[] y)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x will be between 1 and 1,000,000, inclusive.
-Each element of y will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{1, 2, 4, 9}
{1, 1, 1, 1}

Returns: {0, 1, 3, 10 }

Here is one possible way to get the minimal number of moves:

for 1 checker: do nothing
for 2 checkers: put the first two checkers at cell (1, 1)
for 3 checkers: put the first three checkers at cell (2, 1)
for 4 checkers: put all the checkers at cell (3, 1)



1)
{15, 15, 14, 16}
{14, 16, 15, 15}

Returns: {0, 2, 3, 4 }

Whenever we need to have more than one checker in a single cell, we can put them in cell (15, 15).

2)
{4, 4}
{7, 7}

Returns: {0, 0 }

They are already at the same cell.

*/
// END CUT HERE
import java.util.*;
public class TheTower
{
	public int[] count(int[] x, int[] y) 
	{
		for (int i = 0; i < x.length; ++i)
            for (int j = 0; j < x.length; ++j)
                if (i != j)
	}

	/*
	public static void main(String[] args) 
	{
		TheTower temp = new TheTower();
		System.out.println(temp.count(int[] x, int[] y));
	}
	*/
}
