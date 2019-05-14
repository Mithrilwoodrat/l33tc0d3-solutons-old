// https://leetcode.com/problems/maximum-product-subarray/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<list>
#include<map>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> dp(len);
        int ans = nums[0];
        dp[0] = nums[0];
        for (int i=1;i<len;i++) {
            dp[i] = nums[i] + (dp[i-1] > 0?dp[i-1]:0);
            ans = max(dp[i], ans);
        }
        return ans;
    }
    int maxProductOld(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<vector<int> > dp(len);
        int i,j;
        // init 2d dp array with 0
        for (i=0;i<len;i++) {
            dp[i].assign(len, 0);
            dp[i][i] = nums[i];
        }
        int ans = nums[0];
        for (int i=0;i<len;i++) {
            int tmp = dp[i][i];
            for (int j=i+1;j<len;j++) {
                dp[i][j] = nums[j] * (dp[i][j-1]);
                tmp = max(nums[j], dp[i][j]);
                ans = max(ans, tmp);
            }
            cout << ans << endl;
        }
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int imax = nums[0];
        int imin = nums[0];
        int tmp = 0;
        int ans = imax;
        for (int i=1;i<len;i++) {
            if (nums[i] < 0) {
                tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(nums[i]*imax, nums[i]);
            imin = min(nums[i]*imin, nums[i]);
            ans = max(imax, ans);
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums {2, 3, -2, 4};
    auto answer = s.maxProduct(nums);
    cout << answer << endl;
    vector<int> nums1 {-2, 0,-1};
    auto answer1 = s.maxProduct(nums1);
    cout << answer1 << endl;
    vector<int> nums2 {2,-5,-2,-4,3};
    auto answer2 = s.maxProduct(nums2);
    cout << answer2 << endl;
}