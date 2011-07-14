// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You just entered a strange town. The town is currently inhabited by M monsters and B bunnies.



The inhabitants interact in the following way: Whenever two bunnies meet, nothing happens.
Whenever a monster meets a bunny, the monster eats the bunny.
Whenever two monsters meet, they start fighting and they both die in the fight.



Whenever you meet a bunny, you can decide whether you kill it or not.
A bunny will never kill you. You can not kill a monster. However, if you meet a monster, it will kill you without
hesitation.



All the town's inhabitants roam the town at random. More precisely, we will make the following assumptions.



Meetings will occur at different moments in time.
Each time exactly two beings will meet.
Those two beings are always chosen uniformly at random from the set of all living beings in town, including you.



You win if at some moment you can not be killed anymore.
You are not allowed to leave the town until you either win or get killed.



Write a method that will calculate the expected probability that you will win.


DEFINITION
Class:MonstersAndBunnies
Method:survivalProbability
Parameters:int, int
Returns:double
Method signature:double survivalProbability(int M, int B)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.
-When deciding whether to kill a bunny you just met, your only goal is to maximize your winning probability.


CONSTRAINTS
-M will be between 0 and 1,000, inclusive.
-B will be between 0 and 1,000, inclusive.


EXAMPLES

0)
0
0

Returns: 1.0

This town is empty. As soon as you enter it, you win.

1)
0
47

Returns: 1.0

Peaceful bunny pastures, you will not get killed here.

2)
1
0

Returns: 0.0

Sooner or later the monster will find you and kill you.

3)
1
47

Returns: 0.0

The bunnies won't help you. Sooner or later the monster will find you and kill you.

4)
2
0

Returns: 0.3333333333333333

In 1/3 of all cases the two monsters meet first, kill each other and you win. In the other 2/3 cases, one of the two monsters meets you first and kills you.

*/
// END CUT HERE
import java.util.*;
public class MonstersAndBunnies
{
	public double survivalProbability(int m, int b)
	{
        double res = 1.0;
        if (m == 0)
            return 1.0;
        if (m % 2 == 0)
            return 1 / (double) (m + 1);
        return 0.0;
	}

	/*
	public static void main(String[] args) 
	{
		MonstersAndBunnies temp = new MonstersAndBunnies();
		System.out.println(temp.survivalProbability(int M, int B));
	}
	*/
}
