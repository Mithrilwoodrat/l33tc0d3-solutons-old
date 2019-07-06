// https://leetcode.com/problems/shuffle-an-array/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> original;
    vector<int> nums;
    Solution(vector<int> nums) {
        this->nums = nums;
        std::copy(nums.begin(), nums.end(), back_inserter(original));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // vector<int> tmp;
        // vector<int> result;
        // std::copy(original.begin(), original.end(), back_inserter(tmp));
        // for (int i=0;i<original.size();i++) {
        //     int choice = tmp.size()==1?0:rand() % (tmp.size()-1);
        //     result.push_back(tmp[choice]);
        //     cout << choice << endl;
        //     tmp.erase(tmp.begin() + choice);
        // }       
        // return result;
        random_shuffle(nums.begin(),nums.end());
        return nums;
    }
};

int main() {
    vector<int> nums {1, 2, 3};
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();
    for(auto &i:param_2)
        cout << i << " ";
    cout << endl;
}