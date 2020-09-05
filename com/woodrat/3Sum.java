package com.woodrat;
import java.util.*;

// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4] [-4, -1, -1, 0, 1, 2]
// Output: [[-1,-1,2],[-1,0,1]]

// 排序后使用双指针，和小于0则加上左侧更大的负数
class Solution15 {
    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums.length < 3) {
            return result;
        }
        Arrays.sort(nums);
        for (int i =0;i<nums.length-2;i++) {
            if (nums[i]>0) { // 都是正数，无解
                return result;
            }
            if (i == 0 || i>0 && nums[i] != nums[i-1]) {
                int j = i+1;
                int k = nums.length-1;
                int sum = 0 - nums[i];
                while(j<k) {
                    // find an answer
                    if (nums[j] + nums[k] == sum) {
                        result.add(Arrays.asList(nums[i],nums[j], nums[k]));
                        // 跳过相同的数字
                        while(j<k && nums[j] == nums[j+1]) { 
                            j++;
                        }
                        while(j<k && nums[k] == nums[k-1]) {
                            k--;
                        }
                        j++;
                        k--;
                    } else if (nums[j]+nums[k] < sum) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return result;
    }
    
    public static void main(final String[] args) {
        //int[] nums = {-1,0,1,2,-1,-4};
        int[] nums = {1,-1,-1,0};
        List<List<Integer>> result = threeSum(nums);
        for (List<Integer> li : result) {
            for (Integer i : li) {
                System.out.printf("%d ,", i);
            }
            System.out.println();
        }
    }
}