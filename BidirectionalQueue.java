// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a bidirectional cyclical queue which contains N elements. You need to extract several elements from this queue.

You can do 3 kinds of operations with this queue:

Extract first element. After applying this operation, queue a1, ..., aK becomes a2, ..., aK.

Shift queue elements left. After applying this operation, queue a1, ..., aK becomes a2, ..., aK, a1.

Shift queue elements right. After applying this operation, queue a1, ..., aK becomes aK, a1, ..., aK-1.

You are given the initial number of elements in the queue N and a int[] indices which contains the initial (1-based) positions of wanted elements in the queue. Return the minimal number of left and right shifts you'll have to perform to extract the wanted elements in the given order.

DEFINITION
Class:BidirectionalQueue
Method:extractElements
Parameters:int, int[]
Returns:int
Method signature:int extractElements(int N, int[] indices)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-indices will contain between 1 and N elements, inclusive.
-Each element of indices will be between 1 and N, inclusive.
-All elements of indices will be distinct.


EXAMPLES

0)
10
{1, 2, 3}

Returns: 0

The elements are extracted in the same order as they appear in the queue, so no shifts are required.

1)
10
{2, 9, 5}

Returns: 8

To extract the first wanted element, 1 left shift is required. After this the next wanted element will be 7th in a queue with 9 elements, so to extract it 3 right shifts are required. Finally, the last wanted element will be 5th in a queue with 8 elements, so either 4 left shifts or 4 right shifts are required.

2)
32
{27, 16, 30, 11, 6, 23}

Returns: 59



3)
10
{1, 6, 3, 2, 7, 9, 8, 4, 10, 5}

Returns: 14



*/
// END CUT HERE
import java.util.*;
public class BidirectionalQueue
{
	public int extractElements(int N, int[] indices)
	{
        int[] q = new int[N];
        int len = N;
        int res = 0;

        for (int i = 0; i < N; ++i)
            q[i] = i+1;
        for (int i = 0; i < indices.length(); ++i)
        {
            int j = 0;
            while (q[j] != indices[i])
                ++j;
            ++j;
            if (j <= (len+1)/2)
            {
                for (int k = 0
            }
            else
            {}
        }
	}

	/*
	public static void main(String[] args) 
	{
		BidirectionalQueue temp = new BidirectionalQueue();
		System.out.println(temp.extractElements(int N, int[] indices));
	}
	*/
}
