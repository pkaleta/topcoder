// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Tanya has a rectangular table filled with letters.

First, she makes four copies of this table, and arranges the copies as a 2×2 rectangle.

Then she lists all subrectangles of the resulting table.

For example, for the following original table:
OK
she will arrange the copies like this:

OKOK
OKOK

and then she will list the following 30 subrectangles (dots for clarity only):

OKOK .... OKOK OKO. .... OKO. .KOK .... .KOK
OKOK OKOK .... OKO. OKO. .... .KOK .KOK ....

OK.. .... OK.. .KO. .... .KO. ..OK .... ..OK 
OK.. OK.. .... .KO. .KO. .... ..OK ..OK .... 

O... .... O... .K.. .... .K.. ..O. .... ..O. ...K .... ...K 
O... O... .... .K.. .K.. .... ..O. ..O. .... ...K ...K ....

(Note that she is considering all subrectangles based on their positions rather than their content, so the same subrectangle might appear multiple times in the list.  In this case, subrectangle "K" appears four times because it occurs at four different positions.)

Tanya wonders how frequently each letter of the alphabet occurs among all these subrectangles.  You are given a String[] table, where the j-th character of the i-th element is the letter at row i, column j of the original table.  Return a long[] containing exactly 26 elements, where the i-th element is the number of occurrences of the i-th letter in the alphabet among all of Tanya's subrectangles.  'A' is the 0-th letter, 'B' is the 1-st letter, etc.


DEFINITION
Class:SubrectanglesOfTable
Method:getQuantity
Parameters:String[]
Returns:long[]
Method signature:long[] getQuantity(String[] table)


CONSTRAINTS
-table will contain between 1 and 50 elements, inclusive.
-Each element of table will contain between 1 and 50 characters, inclusive.
-Each element of table will contain the same number of characters.
-Each element of table will contain only uppercase letters ('A'-'Z').


EXAMPLES

0)
{"OK"}

Returns: {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

The 30 Tanya's rectangles are listed above. There is a total of 40 Ks and 40 Os in these rectangles.

1)
{"GOOD", "LUCK"}

Returns: {0, 0, 320, 280, 0, 0, 280, 0, 0, 0, 280, 280, 0, 0, 640, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0 }

The four copies form the following table:
GOODGOOD
LUCKLUCK
GOODGOOD
LUCKLUCK

Tanya lists 360 rectangles that contain a total of 320 Cs, 280 Ds, 280 Gs, 280 Ks, 280 Ls, 640 Os, and 320 Us.

2)
{"TANYA",
 "HAPPY",
 "BIRTH",
 "DAYYY"}

Returns: {5168, 1280, 0, 1120, 0, 0, 0, 2560, 1472, 0, 0, 0, 0, 1344, 0, 3008, 0, 1536, 0, 2592, 0, 0, 0, 0, 6320, 0 }



*/
// END CUT HERE
import java.util.*;
public class SubrectanglesOfTable
{
    public long[] add(long[] r1, long[] r2)
    {
        long[] res = new long[r1.length];
        for (int i = 0; i < r1.length; ++i)
            res[i] = r1[i] + r2[i];
        return res;
    }

    public long[] sub(long[] r1, long[] r2)
    {
        long[] res = new long[r1.length];
        for (int i = 0; i < r1.length; ++i)
            res[i] = r1[i] - r2[i];
        return res;
    }

    public long[] getQuantity(String[] table)
    {
        long[] res = new long[26];
        long[][][] helper = new long[101][101][26];

        int w = table[0].length() << 1;
        int h = table.length << 1;

        for (int i = 0; i < 26; ++i)
        {
            res[i] = 0;
            for (int j = 0; j < 101; ++j)
                for (int k = 0; k < 101; ++k)
                    helper[j][k][i] = 0;
        }

        for (int j = w - 1; j >= 0; --j)
            for (int i = h - 1; i >= 0; --i)
            {
                int x = 0;
                int y = 0;

                if (j >= table[0].length() && i >= table.length)
                {
                    x = j - table[0].length();
                    y = i - table.length;
                }
                else if (j >= table[0].length())
                {
                    x = j - table[0].length();
                }
                else if (i >= table.length)
                {
                    y = i - table.length;
                }
                else
                {
                    x = j;
                    y = i;
                }

                helper[i][j] = sub(add(helper[i + 1][j], helper[i][j + 1]), helper[i + 1][j + 1]);
                helper[i][j][table[y].charAt(x) - 'A']++;
            }

        for (int top = 0; top < table.length; ++top)
            for (int bottom = top; bottom < table.length; ++bottom)
                for (int left = 0; left < table[0].length(); ++left)
                    for (int right = left; right < table[0].length(); ++right)
                    {
                        long[] a = helper[top][left];
                        long[] b = add(helper[top][right + 1],
                            helper[bottom + 1][left]);
                        long[] c = helper[bottom + 1][right + 1];
                        long[] tmp1 = add(sub(a, b), c);
                        long[] tmp2 = res;
                        res = add(tmp1, tmp2);
                    }
        return res;
	}

	/*
	public static void main(String[] args) 
	{
		SubrectanglesOfTable temp = new SubrectanglesOfTable();
		System.out.println(temp.getQuantity(String[] table));
	}
	*/
}
