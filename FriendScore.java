// BEGIN CUT HERE
// PROBLEM STATEMENT
// You want to determine the most popular person in a social network.  To do this, you will count the number of "2-friends" that each person has.  Person A is called a 2-friend of another person B if they are friends with each other or if there exists some person C who is a friend of both A and B.  The most popular person is the person with the highest number of 2-friends.  (There might be more than one if multiple people all have the maximal number of 2-friends.)

import java.util.*;
public class FriendScore {
	public int highestScore(String[] friends) {
        int[] c = new int[55];
		for (int i = 0; i < 55; ++i)
            c[i] = 0;
		for (int i = 0; i < friends.length; ++i)
            for (int j = 0; j < friends[i].length(); ++j)
            {
                boolean found = false;
                for (int k = 0; k < friends.length; ++k)
                    if (k != i && k != j)
                    {
                        if (friends[i].charAt(k) == 'Y' ||
                            friends[j].charAt(k) == 'Y')
                            found = true;
                    }
                if (friends[i].charAt(j) == 'Y' || found)
                {
                    c[i]++;
                }
            }
        int m = 0;
		for (int i = 0; i < friends.length; ++i)
            if (c[i] > m)
                m = c[i];
        return m;
	}
}
