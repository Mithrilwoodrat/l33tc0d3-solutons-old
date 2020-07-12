class Solution11 {
    public static int maxAreaBruteForce(int[] height) {
        int size = height.length;
        if(size == 0) {
            return 0;
        }
        int max = 0;
        for (int i=0;i<size;i++) {
            for (int j=i+1;j<size;j++) {
                int tmp = Math.min(height[i], height[j]) * (j-i);
                if ( tmp  > max) {
                    max = tmp;
                }
            }
        }
        return max;
    }
    public static void main(final String[] args) {

        // int input = 10;
        // System.out.println(numSquares(input));
        int[] height = {1,8,6,2,5,4,8,3,7};
        System.out.println(maxAreaBruteForce(height));
    }
}