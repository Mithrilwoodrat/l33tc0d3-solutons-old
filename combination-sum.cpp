// https://leetcode.com/problems/combination-sum/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> answers;
    vector<int> candidates;
    int target;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        copy(candidates.begin(),candidates.end(),back_inserter(this->candidates));
        this->target = target;
        vector<int> tmp;
        traceback(target, 0, tmp);
        return answers;
    }

    void traceback(int res, int index, vector<int> answer) {
        if(res < 0) //no answer
            return;
        
        if (res == 0) {
            answers.push_back(answer);
        }

        for (int i=index; i<candidates.size(); i++) {
            answer.push_back(candidates[i]);
            traceback(res-candidates[i], i, answer);
            answer.pop_back();
        }   
    }
};

int main() {
    auto s = Solution();
    vector<int> nums {2,3,5};
    auto answer = s.combinationSum(nums, 8);
    for (int i=0;i<answer.size();i++) {
        for (int j=0;j<answer[i].size();j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}