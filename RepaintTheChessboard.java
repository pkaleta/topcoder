// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
In the attic of your house you found an M×N board, divided into MN unit squares. Some of the squares are black and the others are white. You decided that you will make a chessboard out of the board by cutting out an 8×8 region and throwing away the rest of the board.



The only problem is that the board is not painted in the alternate black/white pattern you need for the chessboard. Thus after you cut out the 8×8 chessboard, you will have to repaint some of the squares. Of course, you can pick which 8×8 region to cut out.



You are given the current colors of the squares as a String[] board. Character c in element r of board is 'W' if the cell at coordinates (r,c) is white, and 'B' if it is black. Your task is to find the minimum number of squares you will need to repaint after cutting out the 8×8 region.


DEFINITION
Class:RepaintTheChessboard
Method:minimumChanges
Parameters:String[]
Returns:int
Method signature:int minimumChanges(String[] board)


NOTES
-On a correctly colored chessboard each square is either black or white, and no two squares that share a side have the same color.   (Note that according to this definition there are two valid colorings: one with a white, the other with a black square in the upper left corner.)


CONSTRAINTS
-board will contain between 8 and 50 elements, inclusive.
-Each element of board will contain between 8 and 50 characters, inclusive.
-All elements of board will have the same length.
-Each character in each element of board will be either 'B' or 'W'.


EXAMPLES

0)
{"BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB"}


Returns: 0

This is a perfect chessboard, no repainting (and no cutting) necessary.

1)
{"WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBBBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW"}

Returns: 1

This is almost a perfect chessboard, except for one square.

(Using 0-based indices, the incorrectly colored square is element 3, character 3 of board.)

2)
{"BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBW"}


Returns: 31

If we take the 8×8 piece in the lower right corner, we will have one white square, and we will only need 31 more.

3)
{"BBBBBBBBBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBBBBBBBBB"}

Returns: 0

Here we have a perfect chessboard in the middle of the given board.

4)
{"WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBBBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWWWB",
 "BWBWBWBW"}

Returns: 2

For this board the minimum number of changes is 2: We need to change one black square into a white one, and one white square into a black one.

5)
{"BWWBWWBWWBWW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBWWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW"}


Returns: 15



*/
// END CUT HERE
import java.util.*;
public class RepaintTheChessboard
{
	public int minimumChanges(String[] b) 
	{
        int res = 1000000;
		for (int i = 0; i <= b.length - 8; ++i)
            for (int j = 0; j <= b[i].length() - 8; ++j)
            {
                String x = "WB";

                for (int z = 0; z < x.length(); ++z)
                {
                    int tmp = 0;
                    for (int m = 0; m < 8; ++m)
                    {
                        for (int n = 0; n < 8; ++n)
                        {
                            char c = b[i + m].charAt(j + n);
                            if (m % 2 == 0)
                            {
                                if (n % 2 == 0 && c != x.charAt(z))
                                    tmp++;
                                if (n % 2 == 1 && c == x.charAt(z))
                                    tmp++;
                            }
                            else
                            {
                                if (n % 2 == 0 && c == x.charAt(z))
                                    tmp++;
                                if (n % 2 == 1 && c != x.charAt(z))
                                    tmp++;
                            }
                        }
                    }
                    if (tmp < res)
                        res = tmp;
                }
            }
        return res;
	}

	/*
	public static void main(String[] args) 
	{
		RepaintTheChessboard temp = new RepaintTheChessboard();
		System.out.println(temp.minimumChanges(String[] board));
	}
	*/
}
