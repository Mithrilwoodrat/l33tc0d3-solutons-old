import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

class Solution4 {
    public static double findMedianSortedArrays(final int[] nums1, final int[] nums2) {
        List<Integer> nums  = Arrays.stream(nums1).boxed().collect(Collectors.toList());
        nums.addAll(Arrays.stream(nums2).boxed().collect(Collectors.toList()));
        Collections.sort(nums);
        int size = nums.size();
        if (size % 2 == 0) {
            int a = nums.get(size/2 - 1);
            int b = nums.get(size/2);
            return (a + b) / 2.0 ; 
        }
        return nums.get(size/2);
    }

    public static void main(final String[] args) {

        // int input = 10;
        // System.out.println(numSquares(input));
        final int[] a = { 1, 2 };
        final int[] b = { 3, 4 };
        System.out.println(findMedianSortedArrays(a,b));
    }
}