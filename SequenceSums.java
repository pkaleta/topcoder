import java.util.*;
public class SequenceSums
{
	public int[] sequence(int N, int L)
	{
        int a = 1, b = N, len = 1000000001;
        boolean found = false;
        for (int i = L; i <= 100 && !found; ++i)
        {
            System.out.println(i + ": ");
            if ((2 * N) % i == 0)
            {
                int tmp = 2 * N / i;
                int x = tmp - (i - 1);

                int aa = x / 2;
                int bb = aa + (i - 1);
                System.out.println("(" + aa + ", " + bb + ")");
                if (bb + aa == tmp && x >= 0)
                {
                    len = bb - aa + 1;
                    a = aa;
                    b = bb;
                    found = true;
                    break;
                }
            }
        }

        int[] res = null;
        if (found)
        {
            res = new int[len];
            for (int i = a; i <= b; ++i)
                res[i - a] = i;
        }
        else
            res = new int[0];
        return res;
    }
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
