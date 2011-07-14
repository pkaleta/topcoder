// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A language teacher in Antarctica wants his students to be able to read as many words as possible.  However, he only has time to teach them K letters.  After that, the students will only be able to read words containing only those K letters.  Your task is to determine which K letters should be taught to maximize the number of words that the students will be able to read.

The Antarctican language is famous because it only contains words that start with "anta" and end with "tica" (quotes for clarity only).  You are given a String[]  words containing all the words in the language.  Return the maximum number of words the students will be able to read if they learn the optimal set of K letters.


DEFINITION
Class:Teaching
Method:count
Parameters:String[], int
Returns:int
Method signature:int count(String[] words, int K)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 8 and 15 lowercase letters ('a'-'z').
-Each element of words will start with "anta" and end with "tica" (quotes for clarity). 
-All elements of words will be distinct.
-K will be between 0 and 26, inclusive.


EXAMPLES

0)
{"antarctica","antahellotica","antacartica"}
6

Returns: 2

If you choose the letters a, c, i, n, t and r, students will be able to read the first and last words.

1)
{"antaxxxxxxxtica","antarctica"}
3

Returns: 0

No word in the Antarctican language contains 3 or fewer distinct letters.

2)
{"antabtica","antaxtica","antadtica","antaetica","antaftica",
 "antagtica","antahtica","antajtica","antaktica"}
8

Returns: 3



*/
// END CUT HERE
import java.util.*;
import static java.util.Arrays.*;
import static java.lang.Integer.*;

public class Teaching
{

	public int count(String[] w, int K)
	{
        int res = 0;
        char[] a = "bdefghjklmopqrsuvwxyz".toCharArray();
        int[] pos = new int[500];
        for (int i = 0; i < a.length; ++i)
            pos[a[i]] = i;
        int bound = 1 << 21, cnt, k;
        boolean flag;
        for (int i = 0; i < w.length; ++i)
            w[i] = w[i].replaceAll("[antic]", "");

        for (int i = 0; i < bound; ++i)
            if (bitCount(i) == K - 5)
            {
                cnt = 0;
                for (int j = 0; j < w.length; ++j)
                {
                    for (k = 0; k < w[j].length(); ++k)
                        if ((i & 1 << pos[w[j].charAt(k)]) == 0)
                            break;
                    if (k == w[j].length())
                        ++cnt;
                }

                res = Math.max(cnt, res);
            }
        return res;
	}

	/*
	public static void main(String[] args) 
	{
		Teaching temp = new Teaching();
		System.out.println(temp.count(String[] words, int K));
	}
	*/
}
