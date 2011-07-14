// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have an infinite number of the following two polyominoes: AAAA and BB.

You are given a String region, filled with characters '.' and 'X'. You need to cover (without overlapping) all the 'X' characters with the given polyominoes.

Return a String that contains the same region with cells marked '.' left untouched, and cells marked 'X' changed to 'A' or 'B', according to the polyomino that covers the cell.

If there is no solution, return the String "impossible" (quotes for clarity only).

If there are multiple solutions, return the lexicographically smallest one.


DEFINITION
Class:LinearPolyominoCovering
Method:findCovering
Parameters:String
Returns:String
Method signature:String findCovering(String region)


NOTES
-A string S is greater than a string T lexicographically if T is a proper prefix of S, or if S has a greater character at the first position where the strings differ.


CONSTRAINTS
-region will contain between 1 and 50 characters, inclusive.
-Each character of region will be either '.' or uppercase 'X'.


EXAMPLES

0)
"XXXXXX"

Returns: "AAAABB"

There is only room for one AAAA polyomino, so there are three possible coverings: "AAAABB", "BBAAAA", and "BBBBBB". The first one is the lexicographically smallest.

1)
"XX.XX"

Returns: "BB.BB"

The empty cell in the middle should be left uncovered, so we can't use the AAAA polyomino here.

2)
"XXXX....XXX.....XX"

Returns: "impossible"

The middle segment of Xs is too narrow for an AAAA polyomino, but is too wide for a BB polyomino.

3)
"X"

Returns: "impossible"



4)
"XX.XXXXXXXXXX..XXXXXXXX...XXXXXX"

Returns: "BB.AAAAAAAABB..AAAAAAAA...AAAABB"

*/
// END CUT HERE
import java.util.*;
public class LinearPolyominoCovering
{
	public String findCovering(String region)
	{
		String res = "";
        int cnt = 0;

        for (int i = 0; i < region.length(); ++i)
        {
            char c = region.charAt(i);
            System.out.println(c);
            if (c == 'X')
                ++cnt;
            else if (c == '.')
            {
                int r = cnt / 4;
                cnt %= 4;
                for (int j = 0; j < r; ++j)
                    res += "AAAA";
                if (cnt % 2 == 0)
                {
                    if (cnt != 0)
                        res += "BB";
                }
                else
                    return "impossible";
                res += ".";
                cnt = 0;
            }
        }
        int r = cnt / 4;
        cnt %= 4;
        for (int j = 0; j < r; ++j)
            res += "AAAA";
        if (cnt % 2 == 0)
        {
            if (cnt != 0)
                res += "BB";
        }
        else
            return "impossible";
        return res;
	}

	
	//public static void main(String[] args) 
	//{
	//	LinearPolyominoCovering temp = new LinearPolyominoCovering();
	//	System.out.println(temp.findCovering(String region));
	//}
	
}
