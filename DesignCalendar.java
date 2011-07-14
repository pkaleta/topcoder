// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// An alien civilization has advanced to the point where it needs to start keeping track of time. Its leaders have therefore decided to design a calendar. Like many Earthly calendars, this calendar is going to be based on the motion of celestial bodies: in particular the calendar must include period of rotation of their planet (a day) and the period of orbit of the planet around the sun (a real year). Unfortunately, just as is the case on Earth, a real year is not necessarily a convenient integer number of days. Their solution to this problem is to define a calendar year, which is an integer number of days long, and periodically insert an extra day into some calendar years (leap years) in order to correct the discrepancy and resychronize the start of the calendar year with the start of the real year. 
The formal requirements for the calendar are as follows:

A normal calendar year is a length of time that is some integer number N days long.
A leap calendar year is exactly one day longer than a normal calendar year (N+1 days long).
Each calendar year is either a normal year or a leap year.
The calendar must have some positive integer period P, such that every P whole consecutive calendar years sum to exactly the same length of time as P real years.

The leaders wish to design the calendar to make the period P as short as possible. A day is dayLength time units long and a real year is yearLength time units long. Return the smallest achievable positive integer value of P.

DEFINITION
Class:DesignCalendar
Method:shortestPeriod
Parameters:int, int
Returns:int
Method signature:int shortestPeriod(int dayLength, int yearLength)


CONSTRAINTS
-yearLength will be between 1 and 1000000000 (10^9), inclusive.
-dayLength will be between 1 and yearLength, inclusive.


EXAMPLES

0)
4
1461

Returns: 4

These are the values for the Earth to the nearest quarter day. A days here is 4 quarter days long and a year is 365 * 4 + 1 = 1461 quarter days long. A single leap year every 4 years keeps the calendar synchronized.

1)
86400
31558150

Returns: 1728

These are the values for the Earth to the nearest second. A calendar with a period of 1728 years would be aligned to the start of the solar year to within a 
second after the first period.

2)
98
100

Returns: 49

3)
1000
50000100

Returns: 10



4)
5673
28565335

Returns: 5673

5)
5555
846555

Returns: 1111

*/
// END CUT HERE
import java.util.*;
public class DesignCalendar
{
    public int gcd(int a, int b)
    {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

	public int shortestPeriod(int d, int y)
	{
		return d / gcd((y - y / d * d), d);
	}

	/*
	public static void main(String[] args) 
	{
		DesignCalendar temp = new DesignCalendar();
		System.out.println(temp.shortestPeriod(int dayLength, int yearLength));
	}
	*/
}
