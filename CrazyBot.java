// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// An out-of-control robot is placed on a plane, and it takes n random steps.  At each step, the robot chooses one of four directions randomly and moves one unit in that direction. The probabilities of the robot choosing north, south, east or west are north, south, east and west percent, respectively.

The robot's path is considered simple if it never visits the same point more than once.  (The robot's starting point is always the first visited point.)  Return a double containing the probability that the robot's path is simple.  For example, "EENE" and "ENW" are simple, but "ENWS" and "WWWWSNE" are not ('E', 'W', 'N' and 'S' represent east, west, north and south, respectively).

DEFINITION
Class:CrazyBot
Method:getProbability
Parameters:int, int, int, int, int
Returns:double
Method signature:double getProbability(int n, int east, int west, int south, int north)


NOTES
-Your return must have relative or absolute error less than 1E-9.


CONSTRAINTS
-n will be between 1 and 14, inclusive.
-east will be between 0 and 100, inclusive.
-west will be between 0 and 100, inclusive.
-south will be between 0 and 100, inclusive.
-north will be between 0 and 100, inclusive.
-The sum of east, west, south and north will be 100.


EXAMPLES

0)
1
25
25
25
25

Returns: 1.0

The robot only takes one step, so it never visits a point more than once.

1)
2
25
25
25
25

Returns: 0.75

The robot will visit its starting point twice only if the two moves are in opposite directions.

2)
7
50
0
0
50

Returns: 1.0

Here, the only possible directions are north and east, so the robot will never visit the same point twice.

3)
14
50
50
0
0

Returns: 1.220703125E-4

Here, the only possible directions are east and west. The only two available paths are "EEEEEEEEEEEEEE" and "WWWWWWWWWWWWWW". The probability is equal to 2 / (2^14).

4)
14
25
25
25
25

Returns: 0.008845493197441101

The probability is quite small for n=14.

NNNEESWSESWW

NWWWNSNEEE
int begin = Math.max(p1.x, p2.x);
int end = Math.min(p1.x, p2.x);
line |= Math.pow(2, begin) - Math.pow(2, end);
p(N, n, e, s, w) = sum(i=14, 12, .., 2, n*p(N-i, n, e, s, w) : )

*/

// END CUT HERE
import java.util.*;
public class CrazyBot
{
    boolean[][] v;
    double n, s, e, w;
    double res;

    private void visit(int i, double p, int x, int y)
    {
        if (v[x][y])
            return;

        if (i == 0)
        {
            res += p;
            return;
        }

        v[x][y] = true;

        visit(i-1, p * n, x, y+1);
        visit(i-1, p * s, x, y-1);
        visit(i-1, p * e, x+1, y);
        visit(i-1, p * w, x-1, y);

        v[x][y] = false;
    }

	public double getProbability(int T, int E, int W, int S, int N)
	{
        n = (double)N / 100;
        s = (double)S / 100;
        e = (double)E / 100;
        w = (double)W / 100;

        res = 0.0;
        v = new boolean[50][50];
        for (int i = 0; i < 50; ++i)
            for (int j = 0; j < 50; ++j)
                v[j][i] = false;

        visit(T, 1, 20, 20);
        return res;
    }

	public static void main(String[] args) 
	{
		CrazyBot temp = new CrazyBot();
		System.out.println(temp.getProbability(14, 25, 25, 25, 25));
	}
}
