// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John and Brus are studying string theory at the university.  Brus has finished his special project - a dictionary that contains all strings of a special type.  Each string in his dictionary contains exactly n occurrences of the lowercase letter 'a', m occurrences of the lowercase letter 'z', and no other letters.  The strings are listed in alphabetical order.

Your task is to help John by finding the k-th (1-based) string in Brus's dictionary.  If there are less than k strings in the dictionary, return an empty String instead.

DEFINITION
Class:TheDictionary
Method:find
Parameters:int, int, int
Returns:String
Method signature:String find(int n, int m, int k)


CONSTRAINTS
-n will be between 1 and 100, inclusive.
-m will be between 1 and 100, inclusive.
-k will be between 1 and 1,000,000,000 inclusive.


EXAMPLES

0)
2
2
2

Returns: "azaz"

There are six strings in the dictionary and the second one is "azaz".

1)
2
2
6

Returns: "zzaa"

This string is the last one in the dictionary.

2)
10
10
1000000000

Returns: ""

There are less than k strings in the dictionary.

3)
7
4
47

Returns: "aaazazaazaz"

*/
// END CUT HERE
import java.util.*;
public class TheDictionary
{
	public String find(int n, int m, int k) 
	{
		
	}

	/*
	public static void main(String[] args) 
	{
		TheDictionary temp = new TheDictionary();
		System.out.println(temp.find(int n, int m, int k));
	}
	*/
}
