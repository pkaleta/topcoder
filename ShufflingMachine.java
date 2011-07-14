// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A card shuffling machine is a device designed to randomize the order of a deck of cards. A particularly poor (but unfortunately relatively common) design of machine works as follows: an integer N is selected uniformly at random between 1 and maxShuffles, inclusive, and a series of N exactly similar deterministic shuffles are performed. A deterministic shuffle is a fixed permutation of the cards. The randomness of the resulting ordering is clearly therefore only dependent on the number of shuffles chosen. After the deck has been shuffled N times, the cards are distributed to the players.
A particularly dishonest player has decided that he wishes to cheat. He has identified K cards in the deck that he wants to receive when the cards are distributed. He has managed to figure out both the fixed shuffle that the machine uses and also the maximum number of shuffles chosen. The fixed shuffle is given in a int[] shuffle, in which element i gives the position after the shuffle of the card that was initially in position i (both 0-based). The positions in the deck of the cards the player will receive after they have been shuffled are given in cardsReceived (0-based). Before the cards are shuffled, the player can order them in any way he wishes. Determine the initial ordering that will maximize the expected number of the K desired cards that he will receive and return this expected number.

DEFINITION
Class:ShufflingMachine
Method:stackDeck
Parameters:int[], int, int[], int
Returns:double
Method signature:double stackDeck(int[] shuffle, int maxShuffles, int[] cardsReceived, int K)


NOTES
-Your return value must be accurate to an absolute or relative tolerance of 1e-9.


CONSTRAINTS
-shuffle will contain between 1 and 50 elements, inclusive.
-shuffle will be a permutation of the numbers between 0 and M-1, inclusive, where M is the number of elements in shuffle.
-maxShuffles will be between 1 and 100, inclusive.
-cardsReceived will contain between 1 and M elements, inclusive.
-Each element of cardsReceived will be between 0 and M-1.
-The elements of cardsReceived will be distinct.
-K will be between 1 and M, inclusive.


EXAMPLES

0)
{1,0}
3
{0}
1

Returns: 0.6666666666666666

This deck contains only 2 cards and they swap positions after each shuffle. The cheating player receives first card in the deck after the shuffling is completed and he wants to receive 1 of the cards in the deck. If the deck is shuffled 1 or 3 times, he will receive the card that was initially in position 1. If the deck is shuffled 2 times, he will receive the card in position 0. It is therefore optimal to put the card that he wants in position 1 and he will receive it 2 times out of 3.

1)
{1,2,0}
5
{0}
2

Returns: 0.8

If he puts the cards he wants in positions 1 and 2, he will receive one of them 4 times out of 5.

2)
{1,2,0,4,3}
7
{0,3}
2

Returns: 1.0

If he puts the cards in positions 3 and 4, he will receive exactly one of them, regardless of how many shuffles are chosen.

3)
{0,4,3,5,2,6,1}
19
{1,3,5}
2

Returns: 1.0526315789473684



4)
{3,4,7,2,8,5,6,1,0,9}
47
{6,3,5,2,8,7,4}
8

Returns: 6.297872340425532

*/
// END CUT HERE
import java.util.*;
public class ShufflingMachine
{
	public double stackDeck(int[] shuffle, int maxShuffles, int[] cards, int K) 
	{
        int[] c = new int[shuffle.length];
        int[] z = new int[shuffle.length];
        for (int i = 0; i < shuffle.length; ++i)
        {
            c[i] = 0;
            z[i] = i;
        }


        for (int j = 0; j < maxShuffles; ++j)
        {
            for (int i = 0; i < shuffle.length; ++i)
                z[i] = shuffle[z[i]];


            for (int i = 0; i < cards.length; ++i)
                c[z[cards[i]]]++;
        }
        Arrays.sort(c);
        for (int i = 0; i < shuffle.length; ++i)
            System.out.print(c[i] + ", ");
        System.out.println();
        int res = 0;

        for (int i = shuffle.length - 1; i >= shuffle.length - K; --i)
            res += c[i];
        return (double)res / (double)maxShuffles;
	}

	/*
	public static void main(String[] args) 
	{
		ShufflingMachine temp = new ShufflingMachine();
		System.out.println(temp.stackDeck(int[] shuffle, int maxShuffles, int[] cardsReceived, int K));
	}
	*/
}
