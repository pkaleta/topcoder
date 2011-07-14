// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have just entered a knockout tournament with N competitors. The tournament is structured as follows: at the start, the competitors are written down in a list. Adjacent competitors in the list are then paired off, starting from the first competitor on the list, and each pair plays a match (competitor 1 plays against 2, 3 plays against 4, etc.). The losers of each match are eliminated and their names are crossed off the list, while the winners progress to the next round. If there are an odd number of competitors in a round, then the last competitor in the list advances to the next round automatically, without having to play a match. This process then repeats with the new list of competitors, until only a single competitor remains, who is declared the winner. Note that the ordering of the competitors is preserved between rounds.
Your arch-rival has also entered the tournament and you want to know when you might end up playing against him. Your position in the list for the first round is you and your rival's position is rival (both indexed from 1). Assuming that both you and your rival win all the matches before you play each other, return the number of the round in which you will meet (counting the rounds from 1).

DEFINITION
Class:KnockoutTourney
Method:meetRival
Parameters:int, int, int
Returns:int
Method signature:int meetRival(int N, int you, int rival)


CONSTRAINTS
-N will be between 2 and 100000, inclusive.
-you and rival will each be between 1 and N, inclusive.
-you and rival will be distinct.


EXAMPLES

0)
16
1
2

Returns: 1

This is a 4 round tournament, with 16 players, so every player plays a match in every round. You are paired with your rival in the first round.

1)
16
8
9

Returns: 4

Despite being adjacent in the list, you are not paired with your rival until the final round.

2)
1000
20
31

Returns: 4



3)
65536
1000
35000

Returns: 16



4)
60000
101
891

Returns: 10



*/
// END CUT HERE
import java.util.*;
public class KnockoutTourney
{
	public int meetRival(int N, int you, int rival)
	{
        int r = 0;
        while (you != rival)
        {
            ++r;
            you = (you + 1) >> 1;
            rival = (rival + 1) >> 1;
        }
        return r;
	}

	/*
	public static void main(String[] args) 
	{
		KnockoutTourney temp = new KnockoutTourney();
		System.out.println(temp.meetRival(int N, int you, int rival));
	}
	*/
}
