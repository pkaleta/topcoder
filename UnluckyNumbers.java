
import java.util.*;

public class UnluckyNumbers {
	public int getCount(int[] luckySet, int n) {
		Arrays.sort(luckySet);
        int i = 0;
        while (luckySet[i] < n)
            ++i;
        if (luckySet[i] == n || i >= luckySet.length || i == 0)
            return 0;

        int a = luckySet[i-1];
        int b = luckySet[i];
        int x = n - a;
        int y = b - n;
        System.out.println(x + ", " + y);
        return x * y - 1;
	}
}
