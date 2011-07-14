import java.util.*;

public class Underprimes {

    private int[] primes;
    int size;

    private int factorsNumber(int n) {
//        System.out.println("*********" + n);
        int i = 0;
        int result = 0;
        while (n > 1) {
            if (n % primes[i] == 0) {
                result++;
                n /= primes[i];
            }
            else
                ++i;
        }
        return result;
    }

	public int howMany(int A, int B) {
        int result = 0;
        boolean isPrime[] = new boolean[100005];
        size = 0;
        primes = new int[100005];

        for (int i = 0; i < 100005; ++i)
            isPrime[i] = true;
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < 100005; ++i)
            if (isPrime[i]) {
//                System.out.println(i + ", ");
                primes[size++] = i;
                int j = i + i;
                while (j < 100005) {
                    isPrime[j] = false;
                    j += i;
                }
            }
        for (int i = A; i <= B; ++i) {
            if (isPrime[factorsNumber(i)]) {
                ++result;
            }
        }
        return result;
	}
}
