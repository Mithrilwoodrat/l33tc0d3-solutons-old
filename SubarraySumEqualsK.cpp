#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<list>
#include<map>

using namespace std;
//https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    void debug_map(map<int, map<int, int>> tmp) {
        for(auto & i : tmp) {
            cout << "i:" << i.first;
            for (auto & j: i.second) {
                cout << "j: " << j.first;
                cout <<"value:" << j.second;
            }
        }
        cout << endl;
    }
    void debug_nums(vector<int>&nums, int i, int j) {
        cout << "nums: ";
        for(;j<=i;j++) {
            cout << nums[j] << " ";
        }
        cout <<endl;
    }
    map<int, map<int, int>> cache;
    int get_sum(vector<int>&nums, int i, int j) {
        int sum=0;
        for(;j<=i;j++) {
            sum += nums[j];
        }
        return sum;
    }
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        int ans=0,tmp=0;
        
        for(int i=0;i<nums.size();i++) {
            int sum = get_sum(nums, i,0);
            for(int j=0;j<=i;j++) {
                //cout << i << "," << j <<endl;
                //debug_nums(nums, i,j);
                
                //cout << "tmp: " << tmp << endl;
                if (sum == k) 
                    ans++;
                sum -= nums[j];
            }
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    // vector<int> nums {1,1,1};
    // auto answer = s.subarraySum(nums, 2);
    // cout << answer << endl;

    vector<int> nums {1,2,3};
    cout << "nums: ";
    for(int j=0;j<nums.size();j++) {
            cout << nums[j] << " ";
    }
    cout <<endl;
    auto answer = s.subarraySum(nums, 3);
    cout << answer << endl;
}