//https://leetcode.com/problems/maximum-subarray/
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
};

int main() {
    auto s = Solution();
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    auto answer = s.maxSubArray(nums);
    cout << answer << endl;
}