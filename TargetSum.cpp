// https://leetcode.com/problems/target-sum/

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
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        if (len == 0)
            return 0;
        return traceback(nums, 0, 0, S);
    }
    int traceback(vector<int>& nums, int i, int tmp, int S) {
        if (i==nums.size())
            return tmp==S;
        return traceback(nums, i+1, tmp+nums[i], S) + traceback(nums, i+1, tmp-nums[i], S);
    }
};

int main() {
    auto s = Solution();
    vector<int> nums {1, 1, 1, 1, 1};
    auto answer = s.findTargetSumWays(nums, 3);
    cout << answer << endl;
}