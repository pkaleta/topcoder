// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The int[] bag describes a bag of non-negative integers. A bag is the same thing as a set, only it may contain repeated elements.
The order of elements in a bag does not matter.



Given two bags A and B, we say that A is a sub-bag of B if A can be obtained by erasing zero or more elements from B.



The weight of a bag is the sum of its elements.



Examples: 
The bags (1,2,1,3,1) and (3,1,1,1,2) are the same, but different from the bag (1,2,3,3). 
Bags (1,2) and (3,1,1) are sub-bags of the bag (1,2,1,3,1), but bag (1,2,2) is not. 
The weight of the bag (1,2,1,3,1) is 1+2+1+3+1=8.



Write a method that will compute how many sub-bags of bag have a prime weight.


DEFINITION
Class:PrimeSums
Method:getCount
Parameters:int[]
Returns:long
Method signature:long getCount(int[] bag)


NOTES
-A prime number is a positive integer with exactly two positive integer divisors.
-Zero (0) and one (1) are not prime numbers.


CONSTRAINTS
-bag will contain between 1 and 50 elements, inclusive.
-Each element in bag will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{1,1,2,7}

Returns: 5


This bag has 12 different sub-bags: (1,1,2,7), (1,2,7), (2,7), (1,1,7), (1,7), (7), (1,1,2), (1,2), (2), (1,1), (1), and ().


Out of these 12, 5 have prime weights: (1,1,2,7) has weight 11, (7) has weight 7, (1,2) has weight 3, and both (2) and (1,1) have weight 2.


1)
{1,1,1,1,1,1,1,1,1,1}

Returns: 4

This bag has eleven different sub-bags. Out of them four have prime weights (2, 3, 5, and 7).

2)
{4,6,8,10,12,14}

Returns: 0

The empty sub-bag has weight zero, and any other sub-bag has an even weight greater than 2.

3)
{1,2,4,8,16,32,64,128}

Returns: 54



4)
{1234,5678,9012,3456,7890,2345,6789,123,4567,8901}

Returns: 97



5)
{0,0,7}

Returns: 3



*/
// END CUT HERE
import java.util.*;
public class PrimeSums
{

	public long getCount(int[] bag)
	{
        boolean[] isPrime = new boolean[500005];
        int[] dp = new int[500005];
        int res = 0;

        for (int i = 0; i < 500005; ++i)
        {
            dp[i] = -1;
            isPrime[i] = true;
            int stop = (int) Math.sqrt(i);
            for (int j = 2; j <= stop; ++j)
                if (i % j == 0)
                {
                    isPrime[i] = false;
                    break;
                }
        }
        isPrime[0] = isPrime[1] = false;

        dp[0] = 0;

        for (int i = 0; i < 490005; ++i)
        {
            for (int j = 0; j < bag.length; ++j)
                if (dp[i] >= 0)
                    dp[i + bag[j]] += dp[i] + 1;
        }

        for (int i = 0; i < 14; ++i)
            System.out.print(dp[i] + ", ");
        System.out.println();

        for (int i = 0; i < 500005; ++i)
            if (isPrime[i] && dp[i] > 0)
                res += dp[i];

        return res;
	}

	/*
	public static void main(String[] args) 
	{
		PrimeSums temp = new PrimeSums();
		System.out.println(temp.getCount(int[] bag));
	}
	*/
}
