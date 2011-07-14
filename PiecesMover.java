// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a 5x5 board containing at most 5 pieces.  Your task is to move the pieces so that the cells occupied by them form a connected component.  A connected component is a set of cells where each pair of cells is connected by at least one path.  Consecutive cells in a path must all be adjacent.  Two cells are called adjacent if they share a common edge.
You are given a String[] board, where the j-th character of the i-th element is '*' if cell (i, j) is occupied by a piece and '.' otherwise.  Return the minimum number of moves required to achieve your goal.  Each move consists of moving one piece to an adjacent empty cell.

DEFINITION
Class:PiecesMover
Method:getMinimumMoves
Parameters:String[]
Returns:int
Method signature:int getMinimumMoves(String[] board)


CONSTRAINTS
-board will contain exactly 5 elements.
-Each element of board will contain exactly 5 characters.
-Each character in board will be either '.' or '*'.
-board will contain between 1 and 5 '*' characters, inclusive.


EXAMPLES

0)
{".....",
 "..**.",
 ".....",
 "...*.",
 "....."}


Returns: 1


 + + + + +
          
 + + O O +
          
 + + + O +
       |  
 + + + . +
          
 + + + + +

1)
{".....",
 ".....",
 ".**..",
 ".*...",
 "**..."}


Returns: 0

The cells occupied by pieces have already formed a connected component.

2)
{"*...*",
 ".....",
 ".....",
 ".....",
 "*...*"}


Returns: 12


 . + +-+-.
 |   |    
 + + + + +
 |   |    
 +-O O O-+
         |
 + O + + +
   |     |
 .-+ + + .

*/
// END CUT HERE
import java.util.*;
public class PiecesMover
{
	public int getMinimumMoves(String[] board) 
	{
		
	}

	/*
	public static void main(String[] args) 
	{
		PiecesMover temp = new PiecesMover();
		System.out.println(temp.getMinimumMoves(String[] board));
	}
	*/
}
