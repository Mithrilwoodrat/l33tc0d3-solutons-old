// https://leetcode.com/problems/house-robber/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

//https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int>dp(nums.size()+1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=1;i<nums.size();i++) {
            dp[i+1] = max(dp[i], dp[i-1]+nums[i]);
            //cout << dp[i-1] << dp[i] << dp[i+1] << endl; 
        }
        return dp[nums.size()];
    }
};

int main() {
    auto s = Solution();
    vector<int> nums {2,7,9,3,1};
    auto answer = s.rob(nums);
    cout << answer << endl;
}