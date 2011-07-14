// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have a n x n board and several checkers placed on it. The i-th checker is in the cell at row x[i], column y[i]. All coordinates are 1-based. There can be more than one checker in the same cell. A move consists of taking one checker and moving it one cell up, down, left or right.



You want to put each checker in one of the four corners of the board. Return the minimum number of moves necessary to achieve the goal.



DEFINITION
Class:TheSimpleGame
Method:count
Parameters:int, int[], int[]
Returns:int
Method signature:int count(int n, int[] x, int[] y)


CONSTRAINTS
-n will be between 1 and 100, inclusive.
-x will contain between 1 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x will be between 1 and n, inclusive.
-Each element of y will be between 1 and n, inclusive.


EXAMPLES

0)
4
{2}
{3}

Returns: 2

You need two moves to put the only checker to cell (1, 4).

1)
3
{2, 2, 1, 3}
{2, 2, 3, 1}

Returns: 4

For the first two checkers you can choose any of the four corners.

2)
7
{7, 1, 7, 7, 1, 7, 1}
{7, 1, 1, 1, 1, 7, 7}

Returns: 0

All checkers are already in the corners.

*/
// END CUT HERE
import java.util.*;
public class TheSimpleGame
{
	public int count(int n, int[] x, int[] y)
	{
		int res = 0;
        int[] d = new int[4];
        for (int i = 0; i < x.length; ++i)
        {
            d[0] = x[i] - 1 + y[i] - 1;
            d[1] = n - x[i] + y[i] - 1;
            d[2] = n - y[i] + x[i] - 1;
            d[3] = n - y[i] + n - x[i];
            Arrays.sort(d);
            res += d[0];
        }
        return res;
	}

	/*
	public static void main(String[] args) 
	{
		TheSimpleGame temp = new TheSimpleGame();
		System.out.println(temp.count(int n, int[] x, int[] y));
	}
	*/
}
