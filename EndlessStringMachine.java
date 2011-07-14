/*// BEGIN CUT HERE
// PROBLEM STATEMENT
// A certain theoretical machine works by executing a program exactly s times.  The first time it is executed, the program is given the String input as its input.  For each subsequent execution, the program uses the output of the previous execution as its input.

The initial input is a string containing only lowercase letters.  A program is defined as a string containing lowercase letters and '$' characters.  The output of a program is simply this string with all instances of the '$' character replaced by the program's input.  For example, if the input is "a" and the program is "$meric$", the first output would be "america".  The second time it is executed, it will use "america" as its input, and its output will be "americamericamerica".  This process is repeated s times, so for a large s, the output would be: "americamericamericamericamericamericamericamericamericamericamericamericamericamericamerica...".

Given the input, the program and s, return the substring of the machine's final output starting at index min and ending at index max, where min and max are inclusive 1-based indices.  If an index between min and max exceeds the bounds of the final output, put a placeholder '-' character in its place.



DEFINITION
Class:EndlessStringMachine
Method:getFragment
Parameters:String, String, int, int, int
Returns:String
Method signature:String getFragment(String input, String program, int s, int min, int max)


CONSTRAINTS
-input will contain between 1 and 50 characters, inclusive.
-program will contain between 2 and 50 characters, inclusive.
-Each character in input will be a lowercase letter ('a'-'z').
-Each character in program will be '$' or a lowercase letter ('a'-'z').
-The first character in program will be '$'.
-s will be between 1 and 1000000000, inclusive.
-min will be between 1 and 1000000000, inclusive.
-max will be between min and min+99, inclusive.


EXAMPLES

0)
"a"
"$meric$"
6
1
35

Returns: "americamericamericamericamericameri"

This is the example from the statement.

1)
"top"
"$coder"
1
1
20

Returns: "topcoder------------"

One execution is not enough to cover all 20 requested characters. Use the placeholder - character for the indexes that exceed the final output's size.

2)
"abc"
"$x$y$z$"
10
30
50

Returns: "bcyabcxabcyabczabczab"



3)
"xy"
"$a$bb"
12
5000
5099

Returns: "xybbbbaxyaxybbaxyaxybbbbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybb"



// END CUT HERE*/

import java.util.*;

public class EndlessStringMachine {
	public String getFragment(String input, String program, int s, int min, int max) {
		
	}
	/*public static void main(String[] args) {
		EndlessStringMachine temp = new EndlessStringMachine();
		System.out.println(temp.getFragment(String input, String program, int s, int min, int max));
	}*/
}
