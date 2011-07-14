import java.util.*;

public class EqualTowers {

    private static int result = 0;
    private static int h[] = new int[50 * 50001];


    static {
        for (int i = 0; i < 50 * 50001; ++i) {
            h[i] = 0;
        }
    }

    public void calc(int[] bricks, int i, int h) {
        if (i < bricks.length()) {
            if (h[bricks[i]]) {
                if (result < h[bricks[i]])
                    result = h[bricks[i]];
            } else {
                h[bricks[i]] = h;
            }
        }
    }

	public int height(int[] bricks) {
        int t[] = new int[50 * 50001];
        int m = 50 * 50001;
        calc(bricks, )
	}
}
