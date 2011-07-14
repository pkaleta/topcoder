/*// BEGIN CUT HERE
// PROBLEM STATEMENT
// There are several skyscrapers arranged in a row.  You're interested in finding the one from which the maximal number of other skyscrapers can be seen.  The i-th skyscraper can be represented as a line segment on a plane with endpoints (i, 0) and (i, heights[i]).  A skyscraper can be seen from the roof of another skyscraper if a line segment connecting their roofs does not intersect with or touch any other skyscraper.  Return the maximal number of other skyscrapers that can be seen from the roof of some skyscraper.

DEFINITION
Class:BestView
Method:numberOfBuildings
Parameters:int[]
Returns:int
Method signature:int numberOfBuildings(int[] heights)


CONSTRAINTS
-heights will contain between 1 and 50 elements, inclusive. 
-Each element of heights will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{10}

Returns: 0

There's only a single skyscraper, so you can see no other skyscrapers from its roof.


1)
{5,5,5,5}

Returns: 2

From each skyscraper, you can only see its adjacent neighbors.

2)
{1,2,7,3,2}

Returns: 4

You can see all the other skyscrapers from the central one.

3)
{1,5,3,2,6,3,2,6,4,2,5,7,3,1,5}

Returns: 7

You can see seven skyscrapers from the skyscraper with height 7:


4)
{1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5}

Returns: 6

You can see 6 skyscrapers from the skyscraper with height 999999996 - the nearest one to the left and all 5 skyscrapers to the right.

5)
{244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317}

Returns: 7



// END CUT HERE*/

import java.util.*;
import java.awt.Point;
import java.awt.geom.Line2D;

public class BestView {

    private boolean linesIntersect(Point a, Point b, Point c, Point d) {
        int p = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        int q = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
        return p * q <= 0;
    }

	public int numberOfBuildings(int[] h) {

        int res = 0;

	    for (int i = 0; i < h.length; ++i)
        {
            int tmp = 0;

            for (int j = 0; j < h.length; ++j)
                if (i != j) {
                    int start = 0;
                    int end = 0;
                    boolean visible = true;

                    if (i < j) {
                        start = i + 1;
                        end = j;
                    }
                    else if (i > j) {
                        start = j + 1;
                        end = i;
                    }

                    for (int k = start; k < end; ++k)
                        if (Line2D.linesIntersect(i, h[i],
                            j, h[j],
                            k, 0,
                            k, h[k])) {
                            visible = false;
                            break;
                        }

                    if (visible)
                        tmp++;
                }
            res = Math.max(res, tmp);
        }
        return res;
	}
	/*public static void main(String[] args) {
		BestView temp = new BestView();
		System.out.println(temp.numberOfBuildings(int[] heights));
	}*/
}
