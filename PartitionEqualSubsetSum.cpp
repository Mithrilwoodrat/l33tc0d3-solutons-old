//https://leetcode.com/problems/partition-equal-subset-sum/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>

using namespace std;

class SolutionOld {
public:
    vector<int> nums;
    bool found;
    bool traceback(int index, int left, int right) {
        //cout << "index: " << index << "," << left << "," <<right << endl;
        if (index == nums.size()){
            if (left == right) {
                found = true;
                return true;
            }
            return false;
        }
            
        return traceback(index+1, left+nums[index] , right) || traceback(index+1, left, right+nums[index]) ;
    }
    bool canPartition(vector<int>& nums) {
        if (nums.size()==0)
            return false;
        this->nums = nums;
        this->found = false;
        traceback(1, nums[0], 0);
        return found;
    }
};

// 0/1 背包 dp 问题。 寻找 sum/2 的结果
//https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size()==0)
            return false;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        // sum 奇数，无解
        if ((sum & 1) == 1) {
            return false;
        }
        sum /= 2;
        int n = nums.size();
        vector< vector<bool> > dp(n+1, vector<bool>(sum+1, false) );

        for (int i = 1; i < n+1; i++) {
            dp[i][0] = true;
        }
        for (int j = 1; j < sum+1; j++) {
            dp[0][j] = false;
        }

    }
};

int main() {
    auto s = Solution();
    //s: "cbaebabacd" p: "abc"
    //[0, 6]
    vector<int> nums {1, 5, 11, 5};
    auto ans = s.canPartition(nums);
    cout << ans << endl;
    return 0;
}
