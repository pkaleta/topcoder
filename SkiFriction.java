// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Kate is standing on a pair of skis at the beginning of a straight path.  The path consists of n segments of equal length.  You are given a String pathFriction representing the friction of the path. The i-th character of pathFriction is a digit between '1' and '9', inclusive, representing the friction of the i-th segment of the path. (All indices in this problem are 0-based.)

In this problem, we will treat Kate's skis as one single ski. The ski consists of m segments of equal length. A ski segment has the same length as a path segment. The friction of the ski is given in the String skiFriction, where the i-th character is a digit between '1' and '9', inclusive, representing the friction of the i-th segment of the ski.

Initially, Kate is standing in such a way that the i-th segment of her ski touches the i-th segment of the path.  She will move forward one segment at a time until the (m-1)-th segment of her ski touches the (n-1)-th segment of the path.  Each time she moves forward one segment, she moves at the speed of the slowest segment of her ski.  The time required for a segment of her ski to move forward by one segment is equal to the friction of that ski segment plus the friction of the path segment it currently touches.

Return the total time required for Kate to ski to the end of the path.

DEFINITION
Class:SkiFriction
Method:bestPosition
Parameters:String, String
Returns:int
Method signature:int bestPosition(String skiFriction, String pathFriction)


CONSTRAINTS
-skiFriction will contain between 1 and 50 characters, inclusive.
-skiFriction will contain only digits between '1' and '9', inclusive.
-pathFriction will contain between m and 50 characters, inclusive, where m is the number of characters in skiFriction.
-pathFriction will contain only digits between '1' and '9', inclusive.


EXAMPLES

0)
"45"
"15196"

Returns: 33

At the beginning of Kate's first move, the segment of her ski with friction 4 touches the segment of the path with friction 1 (for a total friction of 5).  The segment of her ski with friction 5 touches the segment of the path with friction 5 (for a total friction of 10).  The biggest total friction is 10, so Kate needs 10 seconds to move forward one segment.  On her second move, the total frictions are 4+5 and 5+1, so the biggest one is 9.  On her last move, the total frictions are 4+1 and 5+9, so the the biggest one is 14.  Kate takes a total of 10+9+14 = 33 seconds to ski to the end of the path.

1)
"6"
"65"

Returns: 12

2)
"6723"
"562516639"

Returns: 61

3)
"623883347715596655"
"724951246328811474"

Returns: 0

Kate is already standing at the end of the path.

*/
// END CUT HERE
import java.util.*;
public class SkiFriction
{
	public int bestPosition(String sf, String pf) 
	{
        int res = 0;
        for (int i = 0; i < pf.length() - sf.length(); ++i)
        {
            int max = 0;
            for (int j = 0; j < sf.length(); ++j)
            {
                int s = Integer.parseInt(String.valueOf(sf.charAt(j)));
                int p = Integer.parseInt(String.valueOf(pf.charAt(i + j)));
                System.out.println(s + ", " + p);
                max = Math.max(max, s + p);
            }
            System.out.println("***");
            res += max;
        }
        return res;
	}

	/*
	public static void main(String[] args) 
	{
		SkiFriction temp = new SkiFriction();
		System.out.println(temp.bestPosition(String skiFriction, String pathFriction));
	}
	*/
}
