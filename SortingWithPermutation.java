// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A permutation p[0], p[1], ..., p[n-1] is a sequence containing each number from 0 to n-1 exactly once. The result of applying permutation p to an array a of length n is an array b of length n, where b[p[i]] = a[i] (0-based indices).

Given an array a, find a permutation which has the effect of sorting the elements of a in non-descending order, i.e., an order where each element is greater than or equal to the previous one. If there are several suitable permutations return the lexicographically smallest one.

The permutation p[0], p[1], ..., p[n-1] is considered lexicographically smaller than the permutation q[0], q[1], ..., q[n-1] if there is an index i such that p[i] < q[i] and the equation p[j] = q[j] holds for all j < i.

DEFINITION
Class:SortingWithPermutation
Method:getPermutation
Parameters:int[]
Returns:int[]
Method signature:int[] getPermutation(int[] a)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2, 3, 1}

Returns: {1, 2, 0 }

The element that is originally at position 0 goes to position 1.  The elements originally at positions 1 and 2 go to positions 2 and 0, respectively.

1)
{2, 1, 3, 1}

Returns: {2, 0, 3, 1 }

There are two suitable permutations - {2, 0, 3, 1} and {2, 1, 3, 0}. The first one is lexicographically smaller.

2)
{4, 1, 6, 1, 3, 6, 1, 4}

Returns: {4, 0, 6, 1, 3, 7, 2, 5 }



*/
// END CUT HERE
import java.util.*;
public class SortingWithPermutation
{
	public int[] getPermutation(int[] a)
	{
        int[] res = new int[a.length];
        int[] b = new int[a.length];
        boolean[] used = new boolean[a.length];

        for (int i = 0; i < a.length; ++i)
        {
            b[i] = a[i];
            used[i] = false;
        }

            Arrays.sort(b);

        
        for (int i = 0; i < a.length; ++i)
        {
            System.out.println(a[i]);
            for (int j = 0; j < b.length; ++j)
            {
                if (a[i] == b[j] && !used[j])
                {
                    used[j] = true;
                    res[i] = j;
                    break;
                }
            }
        }
        return res;
	}

	/*
	public static void main(String[] args) 
	{
		SortingWithPermutation temp = new SortingWithPermutation();
		System.out.println(temp.getPermutation(int[] a));
	}
	*/
}
