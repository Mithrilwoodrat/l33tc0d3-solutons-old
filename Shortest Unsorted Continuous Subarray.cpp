//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:

    void debug_nums(vector<int>& nums) {
        for(auto i : nums){
            cout << i << " ";
        }
        cout << endl;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        vector<int> new_nums = nums;
        sort(new_nums.begin(), new_nums.end());
        //debug_nums(new_nums);
        //debug_nums(nums);
        int s=nums.size(),e=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != new_nums[i]) {
                s = min(s,i);
                e = max(e,i);
            }
        }
        //cout << s <<"\t"<< e << endl;
        return e-s >=0?e-s+1:0;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums {2, 6, 4, 8, 10, 9, 1};
    auto answer = s.findUnsortedSubarray(nums);
    cout << answer << endl;
}