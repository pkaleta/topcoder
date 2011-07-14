// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The unicorn is an exotic chess piece similar to the knight. The difference is that while the knight moves two cells in one direction and one in the other direction, the unicorn moves more than two cells in one direction and more than one in the other direction.



More precisely, each unicorn move looks as follows:



pick up the unicorn;
pick one of the four basic directions, and move the unicorn more than two cells in that direction;
pick one of the two basic directions that are orthogonal to the previous one, and move the unicorn more than one cell in that direction;
put down the unicorn.



We have a chessboard that has R rows times C columns. 
Each cell of the chessboard contains one of the first L letters of the alphabet.
To keep the input small, the content of the cells is randomly generated using the method
described below.



You are given the ints R, C, and L described above, an int seed used to generate
the letters in the cells, and a String word. You want to trace the String word by taking a unicorn, placing it onto a cell containing the
first letter of word, making a valid move that takes it onto a cell that contains the second letter, from there making another
move to the third letter, and so on.
Return the number of ways in which this can be done, modulo 1,000,000,007.



The content of the cells is generated using the following pseudocode:


x = seed;
d = (65535 div L)+1;
for (int r=0; r<R; r++)
  for (int c=0; c<C; c++) {
    x = (x * 25173 + 13849) modulo 65536;
    chessboard[r][c] = character with ASCII code (65+(x div d));
  }



DEFINITION
Class:Unicorn
Method:countWays
Parameters:int, int, int, int, String
Returns:int
Method signature:int countWays(int R, int C, int L, int seed, String word)


NOTES
-The path of the unicorn can contain the same cell multiple times.
-In the pseudocode, "A div B" represents the integer part of A/B. For example, 14 div 5 = 2 and 20 div 4 = 5.
-The author's solution does not depend on any properties of the pseudorandom generator. It would solve any input of allowed size within the given limits.


CONSTRAINTS
-R will be between 1 and 300, inclusive.
-C will be between 1 and 300, inclusive.
-L will be between 1 and 26, inclusive.
-seed will be between 0 and 65,535, inclusive.
-word will contain between 1 and 50 characters, inclusive.
-Each character in word will be an uppercase letter ('A'-'Z').


EXAMPLES

0)
3
4
2
47
"AB"

Returns: 2


When generating the input we will compute d=32768, and then generate the content of the cells. The variable x will have the following values, in order: 17332, 39133, 37242, 14235, 656, 12265, 20598, 6471, 51372, 44853, 44210, and 45363. The generated chessboard looks as follows:


ABBA
AAAA
BBBB


There are only two ways a unicorn can trace the word "AB" on this chessboard. It has to start in one of the two top corners, and then jump into the opposite corner.


1)
5
5
2
47
"CD"

Returns: 0

No letter C on this board.


2)
4
4
1
42
"AA"

Returns: 20

The unicorn can start in one of the four corner cells (and then has three possible jumps), or at one of the 8 cells that share a side with a corner cell (and then only have one possible jump). This gives us 4*3 + 8*1 = 20 ways to trace the word.


3)
4
4
1
42
"AAAAA"

Returns: 172



4)
1
1
5
54321
"ABCDE"

Returns: 0

The board is too small. No word longer than one character can be traced as there is no way to make a valid move.

5)
8
8
26
226
"TOPCODER"

Returns: 1

The board looks as follows:

AILFPSPF
DZIOMYCE
QOODZARU
YVOTLTRX
LSRIGANL
LCIUUSNF
IWVXKTDE
OVPPNXRD

If we number the rows and columns starting from 0, with (0,0) being the upper left corner cell, the only valid path of the unicorn is (6,5)-(2,1)-(7,3)-(1,6)-(7,0)-(2,3)-(6,7)-(4,2).

6)
20
20
2
47
"AAAAA"

Returns: 373977054

Do not forget about the modulo; the actual number of paths can be huge.

*/
// END CUT HERE
import java.util.*;
public class Unicorn
{
	public int countWays(int R, int C, int L, int seed, String word) 
	{
		
	}

	/*
	public static void main(String[] args) 
	{
		Unicorn temp = new Unicorn();
		System.out.println(temp.countWays(int R, int C, int L, int seed, String word));
	}
	*/
}
