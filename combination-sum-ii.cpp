// https://leetcode.com/problems/combination-sum-ii/
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        copy(candidates.begin(),candidates.end(),back_inserter(this->candidates));
        this->target = target;
        vector<int> tmp;
        traceback(target, 0, tmp);
        return answers;
    }

    void traceback(int res, int index, vector<int> answer) {
        // cout << "index: " << index << " | ";
        // for (int i=0;i<answer.size();i++) {
        //         cout << answer[i] << " ";
        // }
        // cout << endl;
        if (index == candidates.size()) {
            if (res == 0) {
                bool found = false;
                for (int t=0;t<answers.size();t++) {
                    if (answers[t] == answer) {
                        found = true;
                        break;
                    }
                }
                if (!found)
                    answers.push_back(answer);
            }
            return;
        }
        if (res < 0) {
            return;
        }
        if (res == 0) {
            bool found = false;
            for (int t=0;t<answers.size();t++) {
                if (answers[t] == answer) {
                    found = true;
                    break;
                }
            }
            if (!found)
                answers.push_back(answer);
            return;
        }
        if (candidates[index] > res) {
            return traceback(res, index+1, answer);
        }
        traceback(res, index+1, answer);
        answer.push_back(candidates[index]);
        traceback(res-candidates[index], index+1, answer);
    }
};

int main() {
    auto s = Solution();
    vector<int> nums {10,1,2,7,6,1,5};
    auto answer = s.combinationSum2(nums, 8);
    for (int i=0;i<answer.size();i++) {
        for (int j=0;j<answer[i].size();j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}