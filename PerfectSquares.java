import java.lang.Math;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class PefectSquares {

    private static List<Integer> Squares;
    private static int num;

    public static void initSquares(final int n) {
        Squares = new ArrayList<Integer>();
        Squares.clear();
        final Double m = Math.sqrt(new Double(n));
        for (int i = 1; i < m.intValue(); i++) {
            if (i * i < n) {
                Squares.add(i * i);
            }
        }
        Squares.add(m.intValue() * m.intValue());
    }

    public static void backtrace(final int n, final int sum, final int number, final int i) {
        if (sum == n) {
            if (number < num || num == 0) {
                num = number;
            }

            return;
        }
        if (i < 0) {
            return;
        }
        if (Squares.get(i) > n || sum > n) {
            return;
        }
        if (sum + Squares.get(i) <= n) {
            backtrace(n, sum + Squares.get(i), number + 1, i);
        }
        backtrace(n, sum, number, i - 1);

    }

    public static int numSquaresOld(int n) {
        initSquares(n);
        num = 0;
        backtrace(n, 0, 0, Squares.size() - 1);
        return num;
    }

    public static int numSquares(int n) {
        int[] dp =new int[n+1];
        for (int i = 1;i<=n;i++) {
            int min = Integer.MAX_VALUE;
            Double sqrtD = Math.sqrt(new Double(i));
            int sqrt = sqrtD.intValue();
            if (sqrt * sqrt == i) {
                dp[i] = 1;
                continue;
            }   
            for (int j=1; j<=sqrt; j++) {
                int diff = i - j*j;
                min = Math.min(min, dp[diff]+1);
            }
            dp[i] = min;
        }
        return dp[n];
    }

    public static void main(final String[] args) {

        // int input = 10;
        // System.out.println(numSquares(input));
        int input = 12;
        System.out.println(numSquares(input));
    }
};
