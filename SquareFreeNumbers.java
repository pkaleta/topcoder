// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A number is called square-free if it is not divisible by a perfect square which is greater than one.  A perfect square is the square of an integer.  Return the number of square-free numbers between min and max, inclusive.

DEFINITION
Class:SquareFreeNumbers
Method:getCount
Parameters:long, long
Returns:int
Method signature:int getCount(long min, long max)


CONSTRAINTS
-min will be between 1 and 1,000,000,000,000, inclusive.
-max will be between min and (min + 1,000,000), inclusive.


EXAMPLES

0)
1
10

Returns: 7

Numbers 4, 8 and 9 are not square-free.

1)
15
15

Returns: 1

min and max can be equal.

2)
1
1000

Returns: 608



*/
// END CUT HERE
import java.util.*;
public class SquareFreeNumbers
{
	public int getCount(long min, long max)
	{
        long[] squares = new long[1000005];
        boolean[] divisible = new boolean[1000005];
        for (int i = 0; i < 1000005; ++i)
            divisible[i] = false;

        int i = 2;
        long j;
        int sqrnum = 0;
        while (true)
        {
            j = (long)i*i;
            if (j <= 1000000000000L)
                squares[sqrnum++] = j;
            else
                break;
            ++i;
        }

        for (i = 0; i < sqrnum; ++i)
        {
            j = squares[i] * (long)Math.ceil((double)min / (double)squares[i]);
            while (j <= max)
            {
                if (!divisible[(int)(j - min)])
                    divisible[(int)(j - min)] = true;
                j += squares[i];
            }
        }

        int res = 0;
        for (i = 0; i <= max - min; ++i)
            if (!divisible[i])
                ++res;

        return res;
	}

	public static void main(String[] args) 
	{
		SquareFreeNumbers temp = new SquareFreeNumbers();
		System.out.println(temp.getCount(1000000000000L, 1000001000000L));
	}
}
