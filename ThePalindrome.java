// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John and Brus are studying string theory at the university.  Brus likes palindromes very much.  A palindrome is a word that reads the same forward and backward.  John would like to surprise Brus by taking a String s, and appending 0 or more characters to the end of s to obtain a palindrome.  He wants that palindrome to be as short as possible.  Return the shortest possible length of a palindrome that John can generate.

DEFINITION
Class:ThePalindrome
Method:find
Parameters:String
Returns:int
Method signature:int find(String s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character of s will be a lowercase letter ('a' - 'z').


EXAMPLES

0)
"abab"

Returns: 5

"ababa" is the shortest palindrome that John can get.

1)
"abacaba"

Returns: 7

Already a palindrome.

2)
"qwerty"

Returns: 11

All characters are different.

3)
"abdfhdyrbdbsdfghjkllkjhgfds"

Returns: 38



*/
// END CUT HERE
import java.util.*;
public class ThePalindrome
{
    public boolean isPal(String s)
    {
        for (int i = 0; i < s.length(); ++i)
            if (s.charAt(i) != s.charAt(s.length() - 1 - i))
                return false;
        return true;
    }

	public int find(String s) 
	{
        for (int i = 0; i < s.length(); ++i)
        {
            if (isPal(s.substring(i)))
                return s.substring(i).length() + 2 * (s.length() - s.substring(i).length());
        }
        return 2 * s.length();
	}

	/*
	public static void main(String[] args) 
	{
		ThePalindrome temp = new ThePalindrome();
		System.out.println(temp.find(String s));
	}
	*/
}
