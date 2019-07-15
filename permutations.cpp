// https://leetcode.com/problems/permutations/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> answers;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        traceback(nums, tmp);
        return answers;
    }

    void traceback(vector<int> & nums, vector<int> tmp) {
        if (tmp.size() == nums.size()) {
            answers.push_back(tmp);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            bool found = false;
            for(int j=0;j<tmp.size();j++) {
                if (tmp[j] == nums[i]) {
                    found = true;
                    break;
                }
            }
            if (found)
                continue;
            tmp.push_back(nums[i]);
            traceback(nums, tmp);
            tmp.pop_back();
        }   
    }
};

class Solution2 {
public:
    vector<vector<int>> answers;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        list<int> res;
        for (int i=0;i<nums.size();i++) {
            res.push_back(nums[i]);
        }
        traceback(nums, res, tmp);
        return answers;
    }

    void traceback(vector<int> & nums, list<int> res, vector<int> ans) {
        if (res.empty() || ans.size() == nums.size()) {
            answers.push_back(ans);
            return;
        }
        int tmp = *res.begin();
        ans.push_back(tmp);
        res.pop_front();
        traceback(nums, res, ans);
        res.push_back(tmp);
    }
};

int main() {
    auto s = Solution2();
    vector<int> nums {1,2,3};
    auto answer = s.permute(nums);
    for (int i=0;i<answer.size();i++) {
        for (int j=0;j<answer[i].size();j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}