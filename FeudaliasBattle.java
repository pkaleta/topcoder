import java.util.*;

public class FeudaliasBattle {

    private double dist(int x1, int y1, int x2, int y2) {
        int a = x2 - x1;
        int b = y2 - y1;
        return Math.sqrt(a * a + b * b);
    }

    private double cdist(double dist, int tot, int ms) {
        return ((double)tot / 60) + (dist / (double) ms);
    }

    private double max(double a, double b) {
        if (a > b)
            return a;
        return b;
    }

    private double min(double a, double b) {
        if (a < b)
            return a;
        return b;
    }

	public double getMinimumTime(int[] baseX, int[] baseY, int[] siloX, int[] siloY, int tot, int rechargeTime, int ms) {
        int r = 0;


        double a = dist(siloX[0], siloY[0], baseX[0], baseY[0]);
        double b = dist(siloX[0], siloY[0], baseX[1], baseY[1]);
        double c = dist(siloX[1], siloY[1], baseX[0], baseY[0]);
        double d = dist(siloX[1], siloY[1], baseX[1], baseY[1]);

        double aa = min(
            max(cdist(a, tot, ms), ((double)tot / 60.0) + rechargeTime + cdist(b, tot, ms)),
            max(cdist(b, tot, ms), ((double)tot / 60.0) + rechargeTime + cdist(a, tot, ms))
            );

        double bb = min(
            bb = max(cdist(c, tot, ms), ((double)tot / 60.0) + rechargeTime + cdist(d, tot, ms)),
            bb = max(cdist(d, tot, ms), ((double)tot / 60.0) + rechargeTime + cdist(c, tot, ms))
            );

        double cc = max(cdist(a, tot, ms), cdist(d, tot, ms));
        double dd = max(cdist(b, tot, ms), cdist(c, tot, ms));

        return Math.min(aa, Math.min(bb, Math.min(cc, dd)));
	}
}
